#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include "Armor.h"
#include "Consumable.h"
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"
#include "Scroll.h"
#include "Potion.h"
#include "Creature.h"
#include "XMLSerializable.h"
#include "parseXML.h"
#include "Ammo.h"
#include "OutputXML.h"
#include "SpitOutOntoConsole.h"
#include "Gold.h"
#include "DungeonLevel.h"
#include "CreatureFactory.h"
#include "Player.h"
#include "Tile.h"
#include "ItemFactory.h"

using namespace std;

std::mt19937 mt;

int main(int argc, char * argv[])
{
		cout << "Welcome, my friend to the simplistic game of Trinity’s Nightmare. Here, you have reached " << endl << 
		"the level where you decide the next move. You have also reached the level where the" << endl << 
		"real danger begins. You have conquered the desert of man eating camels. You have trudged" << endl << 
		"through the muddy swamps of the Dr. Heinz’s science experiment’s panting alligator-dogs," << endl << 
		"only to come face to face with the most recent obstacle of the fire-breathing coffee-ingesting" << endl << 
		"cookie-stealing SQUIRRELS!! Now, hold on to you Mountain Dew and Pizza, buckle up into your" << endl <<
		"basement chair, and change your profile picture to that of a face of fear, because here you go…" << endl;


    mt.seed(time(NULL));
	cout << "This is command line" << endl;
	cout << "Arguments Given : " << argc << endl;

//load file into variable
	string inFileName; 
	string outFileName;
	ifstream input;
    int inputValue;
	if (argc >= 3)
	{
		inFileName = argv[1];
		outFileName = argv[2];

	}
	else
	{
		cout << "Enter a file name with .xml exstension: ";
		cin >> inFileName;
		cout << endl;
		cout << "What do you want to name the output file? " ;
		cin >> outFileName;
		cout << endl;
	}
	
	if (argc >= 4)
	{
        inputValue = atoi(argv[3]);
	}
    else
    {
        cout << "How many random Dungeons do you you want generated? " ;
        cin >> inputValue;
        cout << endl;
    }

	if(!input.good())
	{
		cout << "No file by that name. Try Again. " << endl;
		return 1;
	}

	input.open(inFileName.c_str());
//make vector using XMLSerializable pointer
	vector<XMLSerializable*> vWorld;
//send variables to parseXML
	parseXML(input, vWorld);
    //dumpOntoConsole(vWorld);

//make output file
	ofstream output;
   
    bool creatureOccupied;
    bool wallOccupied;

    int tempX;
    int tempY;

    int thingTempX;
    int thingTempY;

    int playerX;
    int playerY;

    Player * pPlayer = new Player();

    char sMove;
    int dNum = 0; 
    vector<DungeonLevel*> vDL;
    vector<Creature*> vCreatures;
    bool nextFloor = true;
    bool sameFloor = false;
    bool prevFloor = false;
    bool creatureTurn;

    initscr();

    while(true)
    {   
        if( nextFloor == true )
        {
            nextFloor = false;
            vDL.push_back(new DungeonLevel(79,20));
            playerX = vDL[dNum]->upstairXCoord();
            playerY = vDL[dNum]->upstairYCoord();
            if( sameFloor == false )
            {
                for(int i = 0 ; i<5; i++)
                {
                    //Creature * pCreature = CreatureFactory::instance().generateCreature(4);
                    vCreatures.push_back(CreatureFactory::instance().generateCreature(vDL.size()));
                    
                    while(true)
                    {
                        thingTempX = mt() % 79;
                        thingTempY = mt() % 20;
                        wallOccupied = vDL[dNum]->checkMove(thingTempX, thingTempY);
                        if( wallOccupied == true )
                        {
                            vDL[dNum]->setCreature(vCreatures[i], thingTempX, thingTempY);
                            vCreatures[i]->setCoords(thingTempX, thingTempY);
                            break;
                        }
                    }
                    /*if( pCreature )
                    {
                        pCreature->dumpObject();
                        delete pCreature;
                    }*/
                }
            }
        }
        else if( prevFloor == true )
        {
            if( dNum < 0 )
            {
                break;
            }
            prevFloor = false;
            playerX = vDL[dNum]->downstairXCoord();
            playerY = vDL[dNum]->downstairYCoord();
        }
        //dl.display();
        //continue;
        cout << endl << "Final State: " << endl << endl;
        tempX = playerX;
        tempY = playerY;
        vDL[dNum]->setCreature(pPlayer, playerX, playerY);
        while(true)
        {
            if(wallOccupied == true)
            {
                vDL[dNum]->removeCreature(playerX, playerY);
                playerX = tempX;
                playerY = tempY;
                vDL[dNum]->setCreature(pPlayer, playerX, playerY);
                creatureTurn = true;
            }
            else
            {
                tempX = playerX;
                tempY = playerY;
            }
            if( creatureTurn == true)
            {
                for( size_t i ; i < vCreatures.size() ; i++ )
                {    
                    thingTempX = vCreatures[i]->getCoordX();
                    thingTempY = vCreatures[i]->getCoordY();
                    vDL[dNum]->removeCreature(thingTempX, thingTempY);
                    if( thingTempX < playerX )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX ++ , thingTempY );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX ++ , thingTempY );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempX ++;
                        }
                    }
                    else if( thingTempX > playerX )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX -- , thingTempY );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX -- , thingTempY );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempX --;
                        }
                    }
                    else if( thingTempY < playerY )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX , thingTempY ++ );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX , thingTempY ++ );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempY ++;
                        }
                    }
                    else if( thingTempY > playerY )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX , thingTempY -- );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX , thingTempY -- );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempY --;
                        }
                    }       
                    vCreatures[i]->setCoords(thingTempX, thingTempY);
                    vDL[dNum]->setCreature(vCreatures[i], thingTempX, thingTempY);
                }
                creatureTurn = false;
            }
            do
            {
                clear();
                for( size_t y = 0; y < 20 ; y++ )
                {
                    for( size_t x = 0; x < 79 ; x++ )
                    {
                        move(y,x);
                        addch(vDL[dNum]->display(x,y));
                    }
                    cout << endl;
                }
                    
                //vDL[dNum]->display();
                refresh();
                sMove = getch();
                if( sMove == 'w' )
                {
                    tempY--;
                    break;
                }
                else if( sMove == 's' )
                {
                    tempY++;
                    break;
                }
                else if( sMove == 'a' )
                {
                    tempX--;
                    break;
                }   
                else if( sMove == 'd' )
                {
                    tempX++;
                    break;
                }
                /*//else if( sMove == "q" )
                {
                    break;
                }*/
                else if( sMove == '>' )
                {
                    if( playerX == vDL[dNum]->downstairXCoord() && playerY == vDL[dNum]->downstairYCoord() )
                    {
                        nextFloor = true;
                        break;
                    }   
                }
                else if( sMove == '<' )
                {
                    if( playerX == vDL[dNum]->upstairXCoord() && playerY == vDL[dNum]->upstairYCoord() )
                    {
                        prevFloor = true;
                        break;
                    }   
                }
                else
                {
                    cout << "What? Try that again please. I have no idea what you meant."<< endl;
                }
            }
            while( sMove != 'q' );
            if( sMove == 'q' )
            {
                break;
            }
            wallOccupied = vDL[dNum]->DungeonLevel::checkMove(tempX,tempY);
            if( nextFloor == true )
            {
                for( size_t i; i < vCreatures.size(); i++ )
                {
                    delete vCreatures[i];
                }
                dNum++;
                break;
            }
            else if( prevFloor == true )
            {
                for( size_t i; i < vCreatures.size(); i++ )
                {
                    delete vCreatures[i];
                }
                dNum--;
                break;
            }
            else
            {
                for( size_t i ; i < vCreatures.size() ; i++ )
                {    
                    thingTempX = vCreatures[i]->getCoordX();
					thingTempY = vCreatures[i]->getCoordY();
                    cout << thingTempX << ", " << thingTempY << endl;
                    if( thingTempX < playerX )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX ++ , thingTempY );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX ++ , thingTempY );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempX ++;
                        }
                    }
                    else if( thingTempX > playerX )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX -- , thingTempY );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX -- , thingTempY );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempX --;
                        }
                    }
                    else if( thingTempY < playerY )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX , thingTempY ++ );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX , thingTempY ++ );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempY ++;
                        }
                    }
                    else if( thingTempY > playerY )
                    {
                        wallOccupied = vDL[dNum]->checkMove( thingTempX , thingTempY -- );
                        creatureOccupied = vDL[dNum]->checkCreature( thingTempX , thingTempY -- );    
                        if( wallOccupied == true && creatureOccupied == false )
                        {
                            thingTempY --;
                        }
                    }       
                    vCreatures[i]->setCoords(thingTempX, thingTempY);
                    vDL[dNum]->removeCreature(thingTempX, thingTempY);
                    vDL[dNum]->setCreature(vCreatures[i], thingTempX, thingTempY);
                }
            }
        }
        if( sMove == 'q' )
        {
            break;
        }
    }
    
    endwin();

    delete pPlayer;
	output.open(outFileName);
	
	outputXML(vWorld, output);
//delete memory to avoid memory leaks
	for(auto it = vWorld.begin() ; it != vWorld.end() ; it++)
	{
		delete (*it);
	}
//close input and output files!
	input.close();
	output.close();
	return 0;
}
