#include <cstdlib>
#include <ncurses.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <iomanip>
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

/////////////////////////////////////////////////////////////////////
////////////////////Extra Credit!!!!!!!!!!!!!!!!!!!!!!///////////////
////////////////////diagonal directions for moves for player/////////
////////////////////diagonal movements for monsters//////////////////
////////////////////regeneration when dying//////////////////////////
////////////////////"God" is a cheat name for loads of health////////
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////Positioning and Why:////////////////////////////
////For positioning I chose to make a new player class that////////// 
////inherits from creature as well as creating a tile class.///////// 
////The tile class holds all possible items and creatures//////////// 
////that are generated. As the player moves across the board/////////
////and comes across a tile that holds an item the player can////////
////access these items via tile and then pick them up. Leaving///////
////an empty tile behind (as a normal ".").//////////////////////////
/////////////////////////////////////////////////////////////////////

using namespace std;

std::mt19937 mt;

int main(int argc, char * argv[])
{
	for(int i = 0; i <14; i++)
	{
		cout << " " << endl;
	}
	cout << "Welcome, my friend to the simplistic game of Trinity's Nightmare. Here, you have" << endl <<
		"reached a dungeon where you are alone, standing with only your car keys and a trash" << endl <<
		"can lid that you found. This is also where the level where the real danger begins." << endl <<
		"You have conquered the attic of man eating camels -- You have trudged through" << endl <<
		"the muddy swamps of Dr. Heinz'science experiment of alligator-dogs, only to" << endl <<
		"come face to face with the most recent obstacle of the fire-breathing" << endl <<
		"coffee-ingesting cookie-stealing SQUIRRELS!! Now, hold on to your" << endl <<
		"Mountain Dew and Pizza, buckle up into your basement chair, and" << endl << 
		"change your profile picture to that of a face of fear, because" << endl <<
		"here you go..." << endl;

	cout << "To Play: " << endl;
	cout << "Unless otherwise declaried, you will show up as @" << endl;
	cout << "1.) Movement:" << endl;
	cout << "     a - moves the player left" << endl;
	cout << "     s - moves the player down" << endl;
	cout << "     d - moves the player right" << endl;
	cout << "     w - moves the player up" << endl;
	cout << "     EXTRA: DIAGONAL:"<< endl;
	cout << "         e - up to the right" << endl;
	cout << "         x - down to the right" << endl;
	cout << "         z - down to the left" << endl;
	cout << "         ` - up to the right" << endl << endl;

	cout << "2.) Picking up and Using Items:" << endl;
	cout << "     p - pick up, and thus using" << endl;

	cout << "3.) Attack:" << endl;
	cout << "     - Creatures will attack you if you are within one space of them." << endl;
	cout << "     - Weapons and Experience increase your attacking." << endl << endl;

	cout << "q will allow you to Quit -- if you are a Quitter..." << endl << endl << endl;

	mt.seed(time(NULL));
	cout << "This is command line" << endl;
	cout << "Arguments Given : " << argc << endl;

//load file into variable
	string inFileName; 
	string outFileName;
	ifstream input;
        int inputValue = 0;
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

    int tempX = 0;
    int tempY = 0;

    int thingTempX = 0;
    int thingTempY = 0;

    int playerX = 0;
    int playerY = 0;

    Player * pPlayer = new Player();
    Weapon * punch = new Weapon();
    Weapon * keys = new Weapon();
    Armor * TrashCanLid = new Armor();


    keys->setDamage(5);
    keys->setAccuracy(2);
    keys->setWeaponType("keychain");
    keys->setName("Car Keys");
    keys->setDisplayChar('x');

    pPlayer->setWeapon(punch);
    
    punch->setDamage(5);
    punch->setAccuracy(5);
    punch->setWeaponType("flesh");

    TrashCanLid->setArmorValue(3);
    TrashCanLid->setArmorType("trashlid");
    TrashCanLid->setName("Trash Can Lid");
    TrashCanLid->setDisplayChar('t');

    pPlayer->setInventory(TrashCanLid);
    pPlayer->setInventory(keys);

    pPlayer->setExperience(0);

    string sMove;
    int dNum = 0; 
    int iNum = 0;
    vector<DungeonLevel*> vDL;
    vector<vector<Creature*>> vvCreatures;
    vector<vector<vector<Item*>>> vvvItems;
    bool nextFloor = true;
    bool sameFloor = false;
    bool prevFloor = false;
    bool creatureTurn;

    int monsterHP = 0;
    int HP = 0;
    int attack = 0;
    int moveCount = 0;
    bool bWeapon = true;

    initscr();
	noecho();

    while(true)
    {   
		clear();
        if( nextFloor == true )
        {
            nextFloor = false;
            if( sameFloor == false )
            {
                vDL.push_back(new DungeonLevel(79,20));
            }
            playerX = vDL[dNum]->upstairXCoord();
            playerY = vDL[dNum]->upstairYCoord();
            vvvItems.resize(dNum+1);
            vvvItems[dNum].resize(5);
            vvCreatures.resize(dNum+1);
            if( sameFloor == false )
            {
                for(int i = 0 ; i<5; i++)
                {
                    //Creature * pCreature = CreatureFactory::instance().generateCreature(4);
                    vvCreatures[dNum].push_back(CreatureFactory::instance().generateCreature((vDL.size())*2));
                    
                    while(true)
                    {
                        thingTempX = mt() % 79;
                        thingTempY = mt() % 20;
                        wallOccupied = vDL[dNum]->checkMove(thingTempX, thingTempY);
                        if( wallOccupied == true )
                        {
                            vDL[dNum]->setCreature(vvCreatures[dNum][i], thingTempX, thingTempY);
                            vvCreatures[dNum][i]->setCoords(thingTempX, thingTempY);
                            break;
                        }
                    }
                    
                    iNum =( (mt() % 5) + 1 );
                    for( size_t j = 0 ; j < iNum ; j++ )
                    {
                        vvvItems[dNum][i].push_back(ItemFactory::instance().generateItem(vDL.size()*20));
                    }

                    while(true)
                    {
                        thingTempX = mt() % 79;
                        thingTempY = mt() % 20;
                        wallOccupied = vDL[dNum]->checkMove( thingTempX, thingTempY );
                        if( wallOccupied == true )
                        {
                            for( size_t j = 0 ; j < iNum ; j++ )
                            {
                                vDL[dNum]->setItems(vvvItems[dNum][i][j], thingTempX,thingTempY);
                                vvvItems[dNum][i][j]->setCoords(thingTempX, thingTempY);
                            }
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
                //cout << "You Escaped... because you ran away like a pansy. Good Job." << endl;
				clear();
				mvprintw(0,0,"You Escaped... because you ran away like a pansy. Good Job. ");
				refresh();
            }
            prevFloor = false;
            playerX = vDL[dNum]->downstairXCoord();
            playerY = vDL[dNum]->downstairYCoord();
        }
        //dl.display();
        //continue;
        //cout << endl << "Final State: " << endl << endl;
        tempX = playerX;
        tempY = playerY;
        vDL[dNum]->setCreature(pPlayer, playerX, playerY);
        while(true)
        {
            if( moveCount % 10 == 0 )
            {
				if(pPlayer->getName() =="God")
				{
					pPlayer->setHP(1000000000);
				}
                else 
				{
					if( pPlayer->getHP() < 97 )
					{
						pPlayer->setHP( pPlayer->getHP() + 3 );
					}
				}
            }
            if( moveCount == 20 )
            {
                vvCreatures[dNum].push_back(CreatureFactory::instance().generateCreature((vDL.size())*2));
                
                while(true)
                {
                    thingTempX = mt() % 79;
                    thingTempY = mt() % 20;
                    wallOccupied = vDL[dNum]->checkMove(thingTempX, thingTempY);
                    if( wallOccupied == true )
                    {
                        vDL[dNum]->setCreature(vvCreatures[dNum][vvCreatures.size()-1], thingTempX, thingTempY);
                        vvCreatures[dNum][vvCreatures.size()-1]->setCoords(thingTempX, thingTempY);
                        break;
                    }
                }
            }
            do
            {
                for( size_t y = 0; y < 20 ; y++ )
                {
                    for( size_t x = 0; x < 79 ; x++ )
                    {
                        move(y,x);
                        addch(vDL[dNum]->display(x,y));
                    }
					refresh();
                    //cout << endl;
                }
				sMove = getch();
				move(23,0);
                clrtoeol();
				move(24,0);
				clrtoeol();
				move(25,0);
				clrtoeol();
				move(26,0);
				clrtoeol();
				move(21,0);
				clrtoeol();
				
                //vDL[dNum]->display();
                //refresh();
				mvprintw(30,0,"Got it. Next? ");
                //cout <<  endl <<"Got it, " << pPlayer->getName() << " What Next? ";
				//getnstr(sMove, sizeof( users_name ) - 1 );
				
                //cin >> sMove;
                //cout << endl;
                if( sMove == "w" )
                {
					//up
                    tempY--;
                    break;
                }
                else if( sMove == "s" )
                {
					//down
                    tempY++;
                    break;
                }
                else if( sMove == "a" )
                {
					//left
                    tempX--;
                    break;
                }   
                else if( sMove == "d" )
                {
					//right
                    tempX++;
                    break;
                }
				else if( sMove == "e" )
                {
					//up to the right
					tempX++;
					tempY--;
					break;
                }
				else if( sMove == "x" )
                {
					//down to the right
					tempX++;
					tempY++;
                    break;
				}
				else if( sMove == "z" )
                {
					//down to the left
        	        tempX--;
					tempY++;
                    break;
                }
				else if( sMove == "`" )
                {
					//up to the left
					tempX--;
					tempY--;
                    break;
                }
                else if( sMove == "q" )
                {
					clear();
					mvprintw(0,0,"Really!? You just quit. Good going.");
                    break;
                }
                else if( sMove == ">" )
                {
                    if( playerX == vDL[dNum]->downstairXCoord() && playerY == vDL[dNum]->downstairYCoord() )
                    {
						clear();
                        nextFloor = true;
                        break;
                    }   
                    pPlayer->setExperience(pPlayer->getExperience() + 5 * vDL.size());
                }
                else if( sMove == "<" )
                {
                    if( playerX == vDL[dNum]->upstairXCoord() && playerY == vDL[dNum]->upstairYCoord() )
                    {
                        prevFloor = true;
                        break;
                    }   
                }
                else if( sMove == "p" )
                {
                    if( vDL[dNum]->checkItem(playerX, playerY) )
                    {
                        vDL[dNum]->pickUpItem(playerX, playerY);
                        if(pPlayer->getDropItem() != NULL)
                        {
                            vDL[dNum]->setItems(pPlayer->getDropItem(), playerX, playerY);
                        }
                        break;
                    }
                }
                else if( sMove == "l" )
                {
                    pPlayer->setDropItem();
                    if( pPlayer->getDropItem() != NULL )
                    {
                        vDL[dNum]->setItems(pPlayer->getDropItem(), playerX, playerY);
                    }
                }
                else if( sMove == "u" )
                {
                    pPlayer->getInventory();
                }
                else
                {
                    //cout << endl << "What!? I try that again. I have no idea what you are trying to do." << endl;
					mvprintw(21,0,"What!? I try that again. I have no idea what you are trying to do.");
                }
				mvprintw(50,0,"Got it, What Next? ");
				refresh();
				
            }while( sMove != "q" );
            if( sMove == "q" )
            {
                //cout << endl << "Really!? You just quit. Good going." << endl;
                break;
            }


            /////////////////////////////////////PLAYER MOVEMENT AND ATTACK///////////////////////////////////////////


            for( size_t i = 0 ; i < vvCreatures[dNum].size() ; i++ )
            {
                if( vvCreatures[dNum][i]->getCoordX() == tempX && vvCreatures[dNum][i]->getCoordY() == tempY )
                {
                    //cout << "creature occupied set to true" << endl;
                    creatureOccupied = true;
                    break;
                }
            }
            wallOccupied = vDL[dNum]->DungeonLevel::checkMove(tempX,tempY);
            if(wallOccupied == true && creatureOccupied == false && ( tempX <! 0 || tempX >! 79 || tempY <! 0 || tempY >! 20 ))
            {
                vDL[dNum]->removeCreature(playerX, playerY);
                playerX = tempX;
                playerY = tempY;
                vDL[dNum]->setCreature(pPlayer, playerX, playerY);
                creatureTurn = true;
            }
            else if( wallOccupied == true && creatureOccupied == true )
            {
                if( bWeapon == false )
                {
                    attack = mt() % (pPlayer->getWeapon())->getDamage();
                }
                else
                {
                    attack = mt() % (punch->getDamage());
                }
                HP = (vDL[dNum]->getCreature(tempX,tempY))->getHP();
                //cout << endl << "Creature's HP before: " << HP << endl;
				mvprintw(24,0,"Creature's HP before: %i", HP);
				refresh();
                (vDL[dNum]->getCreature(tempX,tempY))->setHP(HP - attack);
                //cout << endl << pPlayer->getName() << " attacked " << (vDL[dNum]->getCreature(tempX, tempY))->getName() << " for " << attack << " damage " << endl;
                if( HP - attack <= 0 )
                {
                    for( int i = 0 ; i < vvCreatures[dNum].size() ; i++ )
                    {
                        if( vvCreatures[dNum][i]->getCoordX() == tempX && vvCreatures[dNum][i]->getCoordY() == tempY )
                        {
                            vDL[dNum]->removeCreature( vvCreatures[dNum][i]->getCoordX(), vvCreatures[dNum][i]->getCoordY() );
                            //cout << pPlayer->getName() << " killed " << vvCreatures[dNum][i]->getName() << "!" << endl;
							mvprintw(27,0,"%s killed the creature!",pPlayer->getName().c_str());
                            delete vvCreatures[dNum][i];
                            vvCreatures[dNum].erase(vvCreatures[dNum].begin() + i);
                            break;
                        }
                    }
                    pPlayer->setExperience(pPlayer->getExperience() + vDL.size() * 5);
                }
                else
                {
                    HP = (vDL[dNum]->getCreature(tempX,tempY))->getHP();
                }
                //cout << endl << "Creature's HP after: " << HP << endl;
				mvprintw(26,0,"Creature's HP after: %i", HP);
				refresh();
                creatureOccupied = false;
                tempX = playerX;
                tempY = playerY;
            }
            else if(wallOccupied == false)
            {
                tempX = playerX;
                tempY = playerY;
            }
            //cout << endl << pPlayer->getName() << "'s health is " << pPlayer->getHP() << endl;
			mvprintw(30,0,"%s's health is %i.", pPlayer->getName().c_str(), pPlayer->getHP());
            //cout << endl << "There are " << vvCreatures[dNum].size() << " creatures left on the field. " << endl;
			mvprintw(31,0,"There are %i creatures left on the field. ", vvCreatures[dNum].size());
			//cout << endl << pPlayer->getName() << " has " << pPlayer->getHP() << " Health and " << pPlayer->getExperience() << " Experience right now.";
			mvprintw(32,0,"%s has %i Health and %i Experience right now.",pPlayer->getName().c_str(),pPlayer->getHP(),pPlayer->getExperience());
			//cout << pPlayer->getName() << " killed the monster and gained experience!" << endl;

            ////////////////////////////////////MONSTER MOVEMENT AND ATTACK/////////////////////////////////////////////


            for( size_t i = 0 ; i < vvCreatures[dNum].size() ; i++ )
            {   
                thingTempX = vvCreatures[dNum][i]->getCoordX();
                thingTempY = vvCreatures[dNum][i]->getCoordY();
                //cout << endl << "Creature " << i << " moved from (" << thingTempX << ", " << thingTempY << ") to (";
				//mvprintw("Creature %i moved from (%i,%i) to (", i,thingTempX,thingTempY);
				refresh();
                if( thingTempX < playerX )
                {
                    thingTempX ++;
                }
                else if( thingTempX > playerX )
                {
                    thingTempX --;
                }
                if( thingTempY < playerY )
                {
                    thingTempY ++;
                }
                else if( thingTempY > playerY )
                {
                    thingTempY --;
                }
                for( size_t j = 0 ; j < vvCreatures[dNum].size() ; j++ )
                {
                    if( vvCreatures[dNum][j]->getCoordX() == thingTempX && vvCreatures[dNum][j]->getCoordY() == thingTempY )
                    {
                        creatureOccupied = true;
                    }
                }
				//cout << ")" << endl;
                if(wallOccupied == false)
                {
                    //vDL[dNum]->removeCreature(vvCreatures[dNum][i]->getCoordX(), vvCreatures[dNum][i]->getCoordY());
                    //cout << endl << "restraint" << endl;
					mvprintw(23,50,"You cannot move there...It's a wall.");
                    //vDL[dNum]->setCreature(vvCreatures[dNum][i], vvCreatures[dNum][i]->getCoordX(), vvCreatures[dNum][i]->getCoordY());
                }
                else if( (vDL[dNum]->checkMove(thingTempX, thingTempY) == true && creatureOccupied == false) && (playerX != thingTempX && playerY != thingTempY) )
                {
                    vDL[dNum]->removeCreature(vvCreatures[dNum][i]->getCoordX(), vvCreatures[dNum][i]->getCoordY());
                    vvCreatures[dNum][i]->setCoords(thingTempX, thingTempY);
                    vDL[dNum]->setCreature(vvCreatures[dNum][i], thingTempX, thingTempY);
                }
                else if( ((abs( playerX - thingTempX ) == 1) && (abs( playerY - thingTempY ) == 1)) || (thingTempX == playerX && thingTempY == playerY) )
                {
                    //cout << endl << vvCreatures[dNum][i]->getName() << " attacked " << pPlayer->getName();
					mvprintw(25,0,"%s atacked %s",vvCreatures[dNum][i]->getName().c_str(), pPlayer->getName().c_str());
                    HP = pPlayer->getHP();
                    attack = mt() % punch->getDamage() - (pPlayer->getArmorType())->getArmorValue();
                    if ( attack > 0 )
                    {
                        pPlayer->setHP(HP - attack);
                        //cout << " for " << attack << " damage." << endl;
						mvprintw(25,30," for %i damage.",attack);
						refresh();
                    }
                    else
                    {
						mvprintw(25,30," for 0 damage");
						refresh();
                        //cout << "for 0 damage" << endl;
                    }
                    //If Player Died in the attack:
					if(pPlayer->getHP() <= 0)
					{
						char regen[ 4 ];
						//cout << endl << "You were killed in battle!! Do you want to come back to life? y or n? " << endl;
						mvprintw(40,0,"You were killed in battle!! Do you want to come back to life? y or n? " );
						refresh();
						getnstr( regen, sizeof( regen ) - 1 );
						
						//cin >> regen;
						if (regen == "y")
						{
							pPlayer->setHP(100);
						}
						break;
					}
                    //cout << endl << pPlayer->getName() << " now has " << pPlayer->getHP() << " health left " << endl;
                    //vDL[dNum]->setCreature(vvCreatures[dNum][i], vvCreatures[dNum][i]->getCoordX(), vvCreatures[dNum][i]->getCoordY());
                    creatureOccupied = false;
                }
                //cout << endl << vvCreatures[dNum][i]->getCoordX() << ", " << vvCreatures[dNum][i]->getCoordY() << ")" << endl;
            }
            if( nextFloor == true )
            {
                dNum++;
                if( dNum < vDL.size() )
                {
                    sameFloor = true;
                }
                break;
            }
            else if( prevFloor == true )
            {
                dNum--;
                break;
            }
        }
        if( sMove == "q" )
        {
			//printw("\n You quit... you Quitter!");
			//printw("\n");
            break;
        }
    }

    for( size_t i = 0 ; i < vDL.size() ; i++ )
    {
        for( size_t j ; j < vvCreatures[i].size() ; j++ )
        {
            delete vvCreatures[i][j];
        }
    }

	/*cout << "GAME OVER" << endl;
    cout << "Score - " << pPlayer->getExperience() << endl;
	cout << "Health at the end - " << pPlayer->getHP() << endl;*/
    clear();
	mvprintw(0,0,"GAME OVER" );
	mvprintw(1,0,"Score - %i", pPlayer->getExperience() );
	mvprintw(2,0, "Health at the end - %i", pPlayer->getHP() );
	mvprintw(3,0," ");
	refresh();

    delete pPlayer;
    delete punch;
	delete keys;
	delete TrashCanLid;
	output.open(outFileName);
	
	//outputXML(vWorld, output);
//delete memory to avoid memory leaks
	for(auto it = vWorld.begin() ; it != vWorld.end() ; it++)
	{
		delete (*it);
	}
//close input and output files!
	input.close();
	output.close();
	clear();
	return 0;
}
