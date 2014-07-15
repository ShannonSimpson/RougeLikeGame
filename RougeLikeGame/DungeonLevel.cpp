//Shannon Simpson
//Shannon.Simpson@uky.edu
//CS216 Program 1-3

#include "DungeonLevel.h"

using namespace std;

DungeonLevel::DungeonLevel(int iWidth, int iHeight)
{
	// m_vvTiles is a vector of vectors, so to make it the correct
	// size, first we need to resize the outer vector...
	m_vvTiles.resize(iHeight);

	// And then resize the inner vectors.
	for( auto it = m_vvTiles.begin(); it != m_vvTiles.end(); it++ )
	{
		// Second argument of resize sets any elements that resize
		// creates to that value
		(*it).resize(iWidth, ' ');
	}
	// Initialize and seed the random number engine
    int mainTunnelX = mt() % 80;
    for (size_t y = 0; y <= 19; y++ )
    {
        m_vvTiles[y][mainTunnelX] = '#';
    }

//initialize EVERYTHING! set all bools to false and Counters to 0
	Section0 = false;
	Section1 = false;
	Section2 = false;
	Section3 = false;
	Section4 = false;
	Section5 = false;

	tileCount = 0;
	sectNumTemp = 6;
    int doorCount = 0;
    int roomCount = 0;

    int stairCount = 0;
    int randStairHeight = 0;
    int randStairWidth = 0;
    int randStairNum = 0;
    int counter = 0;
	while(tileCount < 200)
    {
        /*if( counter >= 20 )
        {
            Section0 = false;
            Section1 = false;
            Section2 = false;
            Section3 = false;
            Section4 = false;
            Section5 = false;
            
            // Iterate the outer vector
            for( auto it = m_vvTiles.begin(); it != m_vvTiles.end(); it++ )
            {
                // Iterate the inner vector
                for( auto itInner = (*it).begin();
                    itInner != (*it).end();
                    itInner++ )
                {
                    (*itInner) = ' ';
                }

                // End of line as we just output a row
                //
                cout << endl;
            }
            // Initialize and seed the random number engine
            int mainTunnelX = mt() % 80;
            for (size_t y = 0; y <= 19; y++ )
            {
                m_vvTiles[y][mainTunnelX] = '#';
            }
            counter = 0;
            while( m_vvDoorCoords.size() != 0)
            {
                m_vvDoorCoords.pop_back();
            }
            cout << "retried" << endl;
        }*/
        if(Section0 == true && Section1 == true && Section2 == true && Section3 == true && Section4== true && Section5 == true)
        {
            Section0 = false;
            Section1 = false;
            Section2 = false;
            Section3 = false;
            Section4 = false;
            Section5 = false;
        }
        doorCount = 0;
		collideCheck = false;
	// Calculate random width and height; these both range
	// from 7-13.
		iRandomHeight = 7 + (mt() % 10);
		iRandomWidth = 7 + (mt() % 10);
	// Calculate the start points in both X and Y directions
	// Iterate through both x and y coordinates, and
	// set the tiles to room tiles
		iStartX = mt() % (iWidth - iRandomWidth);
		iStartY = mt() % (iHeight - iRandomHeight);
// FIX ALL MAGIC NUMBERS!!!!	
// gets random setion and then checks to see it the random coordinates landed in the section. If they didn't keep pushing them around (toward the section) until they are in the section. 
		sectNum = (mt() % 6);
		if( sectNum == 0 && Section0 != true )
		{
			while(iStartX + iRandomWidth >= 25)
			{
				iStartX = iStartX - 1;
                //cout << "-X 0" << endl;
			}
			while(iStartY + iRandomHeight >= 9)
			{
				iStartY = iStartY - 1;
                //cout << "-Y 0" << endl;
			}
			while(iStartX < 1)
			{
				iStartX++;
                //cout << "+X 0" << endl;
			}
			while(iStartY < 1)
			{
				iStartY ++;
                //cout << "+Y 0" << endl;
			}
			Section0 = true;
        }
		else if( sectNum == 1 && Section1 != true )
		{
			while(iStartX + iRandomWidth > 52)
			{
				iStartX --;	
                //cout << "-X 1" << endl;
			}
			while(iStartX < 26)
			{
				iStartX ++;
                //cout << "+X 1" << endl;
			}
			while(iStartY + iRandomHeight >= 9)
			{
				iStartY = iStartY - 1;
                //cout << "-Y 1" << endl;
			}
			while(iStartY < 1)
			{
                iStartY ++;
                //cout << "+Y 1" << endl;
			}
			Section1 = true;
		}
		else if( sectNum == 2 && Section2 != true )
		{
			while(iStartX + iRandomWidth <= 53)
			{
				iStartX = iStartX + 1;	
                //cout << "+X 2" << endl;
			}
			while(iStartY + iRandomHeight >= 9)
			{
				if(iStartY > 1)
                {
                    iStartY --;
                    //cout << "-Y 2" << endl;
                }
                else
                {
                    break;
                }
			}
			while(iStartX + iRandomWidth > 78)
			{
				iStartX--;
                //cout << "-X 2" << endl;
			}
			while(iStartY < 1)
			{
				iStartY ++;
                //cout << "+Y 2" << endl;
			}
			Section2 = true;
		}
		else if( sectNum == 3 && Section3 != true )
		{
			while(iStartX + iRandomWidth >= 25)
			{
				iStartX = iStartX - 1;
                //cout << "-X 3" << endl;
			}
			while(iStartY + iRandomHeight <= 9)
			{
				iStartY = iStartY + 1;
                //cout << "+Y 3" << endl;
			}
			while(iStartY > 19)
			{
				iStartY = iStartY - 1;
                //cout << "-Y 3" << endl;
			}
			while(iStartX < 1)
			{
				iStartX = iStartX + 1;
                //cout << "+X 3" << endl;
			}	
			Section3 = true;
		}
		else if( sectNum == 4 && Section4 != true )
		{
			while(iStartX + iRandomWidth >= 52)
			{
				iStartX --;	
                //cout << "minus X 4" << endl;
			}
			while(iStartX + iRandomWidth <= 26)
			{
				iStartX ++;
                //cout << "plus X 4" << endl;
			}
			while(iStartY + iRandomHeight <= 9)
			{
				iStartY = iStartY + 1;
                //cout << "plus Y 4" << endl;
			}
			while(iStartY > 19)
			{
				iStartY = iStartY - 1;
                //cout << "minus Y 4" << endl;
			}
			Section4 = true;
		}
		else if( sectNum == 5 && Section5 != true )
		{
			while(iStartX + iRandomWidth <= 53)
			{
				iStartX = iStartX + 1;	
                //cout << "plus X 5" << endl;
			}
			while(iStartY + iRandomHeight <= 9)
			{
				iStartY = iStartY + 1;
                //cout << "plus Y 5" << endl;
			}
			while(iStartX + iRandomWidth > 78)
			{
				iStartX = iStartX - 1;
                //cout << "minus X 5" << endl;
			}	
			while(iStartY + iRandomHeight > 19)
			{
				iStartY = iStartY - 1;
                //cout << "minus Y 5" << endl;
			}
			Section5 = true;
		}
        cout << "Made it through section sorting" << endl;
        //checks to see if the room collides with any other room. *note* rooms can collide with 'R' because that is a room buffer.
		for( int x = iStartX; x <= iStartX + iRandomWidth; x++ )
		{
			for( int y = iStartY; y <= iStartY + iRandomHeight; y++ )
			{
				if( m_vvTiles[y][x] == '#' || m_vvTiles[y][x] == '|' || m_vvTiles[y][x] == '-' || m_vvTiles[y][x] == '.')
				{
					collideCheck = true;
                    //cout << "Made it through Collide Check" << endl;
				}
			}
		}
        if( collideCheck == true )
        {
            counter ++;
            //cout << "collide Check counter" << endl;
        }
        // if the collide check passes true skip this, but if false build a room
		if(collideCheck != true)
		{
			if(sectNum != sectNumTemp)
			{
                roomCount++;
				for( int x = iStartX; x <= iStartX + iRandomWidth; x++ )
				{
					for( int y = iStartY; y <= iStartY + iRandomHeight; y++ )
					{
                        //fill the outside walls with R as a buffer
                        if( x == iStartX || x == iStartX + iRandomWidth )
						{
							m_vvTiles[y][x] = 'R';
                        }
						else if( y == iStartY || y == iStartY + iRandomHeight )
						{
							m_vvTiles[y][x] = 'R';
                        }
                        //then build actual walls
                        else if( y == iStartY + 1 || y == iStartY + iRandomHeight - 1)
                        {
                            m_vvTiles[y][x] = '-';
                        }
                        else if( x == iStartX + 1 || x == iStartX + iRandomWidth - 1 )
                        {
                            m_vvTiles[y][x] = '|';
                        }
                        //fill in the rest with tiles
						else
						{
							m_vvTiles[y][x] = '.';
							tileCount++;
						}
					}
				}
                //cout << "made room" << endl;
                //adjust the corner points of the rooms to not include the 'R' surrounding it.
                iStartX = iStartX + 1;
                iRandomWidth = iRandomWidth - 2;
                iStartY = iStartY + 1;
                iRandomHeight = iRandomHeight - 2;
                randStairNum = mt() % 2;
                //add stairs to the first two randomly generated rooms
                if(stairCount < 2)
                {
                    if(tileCount > 16)
                    {
                        if( stairCount == 0)
                        {    
                            while(stairCount == 0)
                            {
                                //get randStairHeight/Width and subtract 1 because thatll put it inside of the walls
                                randStairHeight = mt() % iRandomHeight;
                                randStairWidth = mt() % iRandomWidth;
                                if(randStairHeight + iStartY > iStartY && randStairHeight + iStartY < iStartY + iRandomHeight && randStairWidth + iStartX != iStartX && randStairWidth + iStartX != iStartX +  iRandomWidth) 
                                {
                                    m_vvTiles[iStartY + randStairHeight][iStartX + randStairWidth] = '<';
                                    stairCount++;
                                    m_upstairsY = iStartY + randStairHeight;
                                    m_upstairsX = iStartX + randStairWidth;
                                }
                            }
                        }
                        else if( stairCount == 1)
                        {    
                            while(stairCount == 1)
                            {
                                //get randStairHeight/Width and subtract 1 because thatll put it inside of the walls
                                randStairHeight = mt() % iRandomHeight;
                                randStairWidth = mt() % iRandomWidth;
                                if(randStairHeight + iStartY > iStartY && randStairHeight + iStartY < iStartY + iRandomHeight && randStairWidth + iStartX != iStartX && randStairWidth + iStartX != iStartX +  iRandomWidth) 
                                {
                                    m_vvTiles[iStartY + randStairHeight][iStartX + randStairWidth] = '>';
                                    stairCount++;
                                    m_downstairsY = iStartY + randStairHeight;
                                    m_downstairsX = iStartX + randStairWidth;
                                }
                            }
                        }
                    }
                    //cout << "made doors" << endl;
                }
                //add 2 doors to each randomly generated room 
                while(doorCount < 2)
                {
                    randomX, randomY = randomSidePick(iStartX, iStartY , iStartX + iRandomWidth, iStartY + iRandomHeight, mt);
                    if(randomX != 0 || randomY != 0 || randomX != 79 || randomY != 20)
                    {
                        if(m_vvTiles[randomY][randomX] != m_vvTiles[iStartY][iStartX] || m_vvTiles[randomY][randomX] != m_vvTiles[iStartY + iRandomHeight][iStartX] || m_vvTiles[randomY][randomX] != m_vvTiles[iStartY][iStartX + iRandomWidth] || m_vvTiles[randomY][randomX] != m_vvTiles[iStartY + iRandomHeight][iStartX + iRandomWidth])
                        {
                            m_vvTiles[randomY][randomX] = '.';
                            doorCount++;
                            //store doors in a vector for use later with the random tunnel generator
                            m_vvDoorCoords.push_back(randomX);
                            m_vvDoorCoords.push_back(randomY);
                        }
                    }
                    //cout << "made it through door count" << endl;
                }
			}
            //set sectNumTemp equal to sectNum as a last check scenario so we don't get rooms in the same sections if nothing else works
			sectNumTemp = sectNum;
		}
    }
    //call dig tunnels for the amount of doors
    for ( size_t i = 0 ; i <= m_vvDoorCoords.size()-1 ; i++)
    {
        digTunnel(m_vvTiles, m_vvDoorCoords[i], m_vvDoorCoords[i+1], mainTunnelX);
        i++;
        cout << m_vvDoorCoords.size()/2 << endl;
        //cout << "dug tunnel" << endl;
    }
    //cout << "made it out of the dig tunnel loop" << endl;
    //replace all the 'R' with ' '
	for( auto it = m_vvTiles.begin(); it != m_vvTiles.end(); it++ )
	{
		// Iterate the inner vector
		for( auto itInner = (*it).begin(); itInner != (*it).end(); itInner++ )
	    {
            if( (*itInner) == 'R')
            {
                *itInner = ' ';
                //cout << "removed R's" << endl;
            }
		}
	}
	//testLevel(m_vvTiles);
	vector<vector<char>> vLevel;
	vLevel.resize(iHeight);

	// And then resize the inner vectors.
	for( auto it = vLevel.begin(); it != vLevel.end(); it++ )
	{
		// Second argument of resize sets any elements that resize
		// creates to that value
		(*it).resize(iWidth, ' ');
	}
	for( size_t i = 0; i < m_vvTiles.size() ; i++ )
	{
		// Iterate the inner vector
		for( size_t j = 0; j < m_vvTiles[i].size() ; j++ )
	    {
			vLevel[i][j] = m_vvTiles[i][j];
		}
	}
    //cout << "resized vLevel" << endl;
    //test the level
    testLevel(vLevel);
    
    /*for( auto it = vLevel.begin(); it != vLevel.end(); it++ )
    {
        (*it).resize(iWidth, ' ');
    }*/

    m_vvNewTiles.resize(iHeight);
    for( auto it = m_vvNewTiles.begin(); it != m_vvNewTiles.end(); it++ )
    {
        (*it).resize(iWidth);
    }
    for( size_t i = 0; i < m_vvTiles.size(); i++ )
    {
        for( size_t j = 0; j < m_vvTiles[i].size(); j++ ) 
        {
            if( m_vvTiles[i][j] == ' ' || m_vvTiles[i][j] == '|' || m_vvTiles[i][j] == '-')
            {
                occupied = false;
            }
            else if( m_vvTiles[i][j] == '.' || m_vvTiles[i][j] == '#' || m_vvTiles[i][j] == '<' || m_vvTiles[i][j] == '>')
            {
                occupied = true;
            }
            m_vvNewTiles[i][j] = new Tile(m_vvTiles[i][j], occupied);
        }
    }
    //cout << "created m_vvNewTiles" << endl;
}

DungeonLevel::~DungeonLevel(){}

int DungeonLevel::upstairXCoord()
{
    return m_upstairsX;
}

int DungeonLevel::upstairYCoord()
{
    return m_upstairsY;
}

int DungeonLevel::downstairXCoord()
{
    return m_downstairsX;
}

int DungeonLevel::downstairYCoord()
{
    return m_downstairsY;
}

/*void DungeonLevel::display()
{
}*/

int DungeonLevel::display(int x, int y)
{
	//// Iterate the outer vector
	//for( auto it = m_vvNewTiles.begin(); it != m_vvNewTiles.end(); it++ )
	//{
	//	// Iterate the inner vector
	//	for( auto itInner = (*it).begin();
	//		itInner != (*it).end();
	//		itInner++ )
	//    {
	//		cout << (*itInner)->tileDisplayChar();
	//	}

	//	// End of line as we just output a row
	//	cout << endl;
	//}
    return m_vvNewTiles[y][x]->tileDisplayChar();
}

bool DungeonLevel::checkMove(int x, int y)
{
   // return (*m_vvNewTiles[y][x]).Tile::returnBool()
    return m_vvNewTiles[y][x]->returnBool();
}

bool DungeonLevel::checkCreature( int x, int y )
{
    return m_vvNewTiles[y][x]->Tile::returnCreatureBool();
}

bool DungeonLevel::checkItem( int x, int y )
{
    return m_vvNewTiles[y][x]->Tile::returnItemBool();
}

void DungeonLevel::setCreature( Creature * pThing, int x, int y )
{
    m_vvNewTiles[y][x]->Tile::setCreature(pThing); 
}

Creature * DungeonLevel::getCreature(int x, int y)
{
    return m_vvNewTiles[y][x]->Tile::getCreature();
}

void DungeonLevel::setItems( Item * pItem, int x, int y )
{
    m_vvNewTiles[y][x]->Tile::setItems(pItem);
}

void DungeonLevel::removeCreature(int x, int y)
{
    m_vvNewTiles[y][x]->Tile::removeCreature(); 
}

void DungeonLevel::pickUpItem(int x, int y)
{
    m_vvNewTiles[y][x]->Tile::pickUpItem();
}

//this entire function goes through, picks a random side to put a door on, then picks a random X and Y coordinate within the sX and sY and rH and rW to put the door in
int DungeonLevel::randomSidePick(int x1, int y1, int x2, int y2, mt19937 & mt)
{
    randomSide = (mt() % 4);

    if(randomSide == 0)
    {
        if(y1 != 0)
        {
            randomX = x1 + mt() % (x2-x1);
            randomY = y1;
        }
        else if(y1 == 0)
        {
            randomX = x1 + mt() % (x2 - x1);
            randomY = y2;
        }
    }
    else if(randomSide == 1)
    {
        if(y2 != 19)
        {
            randomX = x1 + mt() % (x2-x1);
            randomY = y2;
        }
        else if(y2 == 19)
        {
            randomX = x1 + mt() % (x2 - x1);
            randomY = y1;
        }
    }
    else if(randomSide == 2)
    {
        if(x1 != 0)
        {
            randomX = x1;
            randomY = y1 + mt() % (y2-y1);
        }
        else if(x1 == 0)
        {
            randomX = x2;
            randomY = y1 + mt() % (y2-y1);
        }
    }
    else if(randomSide == 3)
    {
        if(x2 != 79)
        {
            randomX = x2;
            randomY = y1 + mt() % (y2-y1);
        }
        else if(x2 == 79)
        {  
            randomX = x1;
            randomY = y1 + mt() % (y2-y1);
        }
    }
    return randomX, randomY;
}

//this function "digs" out all the tunnels until they get to the main tunnel set at the beginning of DungeonLevel constructor
void DungeonLevel::digTunnel(vector<vector<char>> & m_vvTiles, int doorX, int doorY, int mainTunnelX)
{
    tunnelX = doorX;
    tunnelY = doorY;
    //so while the tunnelX that is being "dug" out is not the mainTunnelX, keep digging. If the next tile over is a anything other than a space, a hashtag, or an R then "go around it"
    num = mt() % 2;
    //cout << "num = " << num << endl;
    while(tunnelX != mainTunnelX)
    {
        cout << "(" << tunnelX << "," << mainTunnelX << ")";
        //cout << "tunnelY: " << tunnelY << endl;
        //if the tunnelX is less than the mainTunnelX, dig to the right
        if(tunnelX < mainTunnelX)
        {
            //cout << "<" << endl;
            if(m_vvTiles[tunnelY][tunnelX + 1] == 'R' || m_vvTiles[tunnelY][tunnelX+1] == ' ' || m_vvTiles[tunnelY][tunnelX+1] == '#')
            {
                tunnelX ++;
                //cout << "x++ <" << tunnelX << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX + 1] == '-' && m_vvTiles[tunnelY + 1][tunnelX] != '.'/* || m_vvTiles[tunnelY][tunnelX+1] == '*/)
            {
                tunnelY ++;
                //cout << "y++ <" << tunnelY << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX + 1] == '-' && m_vvTiles[tunnelY - 1][tunnelX] != '.')
            {
                tunnelY --;
                //cout << "y-- <" << tunnelY << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX + 1] == '.' || m_vvTiles[tunnelY][tunnelX + 1] == '|' || m_vvTiles[tunnelY][tunnelX + 1] == '-')
            {
                //cout << "made it into last else if < " << endl;
                if(m_vvTiles[tunnelY][tunnelX + 1] == '.' && m_vvTiles[tunnelY][tunnelX] == '.')
                {
                    tunnelX --;
                    m_vvTiles[tunnelY][tunnelX] = '#';
                    //cout << "placed tunnel <" << endl;
                }
                while(m_vvTiles[tunnelY][tunnelX + 1] == '|' ||m_vvTiles[tunnelY][tunnelX + 1] == '-' || m_vvTiles[tunnelY][tunnelX + 1] == '.')
                {
                    //cout << "made it into while loop < " << endl;
                   if( num == 0 )
                   {
                       if( tunnelY >! 20)
                       {
                           tunnelY ++;
                           //cout << "while y++ <" << endl;
                       }
                       else
                       {
                            num = 1;
                       }
                   }
                   else if( num == 1)
                   {
                       if( tunnelY <! 0)
                       {
                           tunnelY --;
                           //cout << "while y-- <" << endl;
                       }
                       else
                       {
                            num = 0;
                       }
                   }
                   m_vvTiles[tunnelY][tunnelX] = '#';
                }
            }
        }
        //if the tunnelX is greater than the mainTunnelX, dig to the left
        else if (tunnelX > mainTunnelX)
        {
            cout << ">" << endl;
            if(m_vvTiles[tunnelY][tunnelX - 1] == 'R' || m_vvTiles[tunnelY][tunnelX - 1] == ' ' || m_vvTiles[tunnelY][tunnelX - 1] == '#')
            {
                tunnelX --;
                //cout << "x-- >" << tunnelX << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX - 1] == '-' && m_vvTiles[tunnelY + 1][tunnelX] != '.')
            {
                tunnelY --;
                //cout << "y-- >" << tunnelY << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX - 1] == '-' && m_vvTiles[tunnelY - 1][tunnelX] != '.')
            {
                tunnelY ++;
                //cout << "y++ >" << tunnelY << endl;
            }
            else if(m_vvTiles[tunnelY][tunnelX - 1] == '.' || m_vvTiles[tunnelY][tunnelX - 1] == '|' || m_vvTiles[tunnelY][tunnelX - 1] == '-'  )
            {
                //cout << "made it into last else if > " << endl;
                if(m_vvTiles[tunnelY][tunnelX - 1] == '.' && m_vvTiles[tunnelY][tunnelX] == '.')
                {
                    tunnelX ++;
                    m_vvTiles[tunnelY][tunnelX] = '#';
                    //cout << "x-- >" << tunnelX << endl;
                }
                cout << "not x--" << endl;
                while(m_vvTiles[tunnelY][tunnelX - 1] == '|' || m_vvTiles[tunnelY][tunnelX - 1] == '-' || m_vvTiles[tunnelY][tunnelX - 1] == '.')
                {
                    //cout << "made it into while loop >" << endl;
                   if( num == 0 )
                   {
                       if( tunnelY >! 20)
                       {
                           tunnelY ++;
                           //cout << "while y++ >" << endl;
                           m_vvTiles[tunnelY][tunnelX] = '#';
                       }
                       else
                       {
                            num = 1;
                       }
                   }
                   else if( num == 1)
                   {
                       if( tunnelY <! 0)
                       {
                           tunnelY --;
                           //cout << "while y-- >" << endl;
                           m_vvTiles[tunnelY][tunnelX] = '#';
                       }
                       else
                       {
                            num = 0;
                       }
                   }
                }
            }
        }
        m_vvTiles[tunnelY][tunnelX] = '#';
        //cout << "drew tunnel" << endl;
    }
}

//Marks all positions where there is a period or a hashtag with an X. once returned, if there are any periods left, return statement saying the Dungeon equal specs 
void DungeonLevel::markPosition(vector<vector<char>> & vLevel, int x, int y)
{
    if( vLevel.size() <= y)
        return;
    if( y < 0 )
        return;
    if( vLevel[y].size() <= x )
        return;
    if( x < 0 )
        return;
    char cTile = vLevel[y][x];

    if( cTile != '#' && cTile != '.' )
        return;

    vLevel[y][x] = 'X';

    markPosition(vLevel, x+1, y);
    markPosition(vLevel, x-1, y);
    markPosition(vLevel, x, y+1);
    markPosition(vLevel, x, y-1);
}


bool DungeonLevel::testLevel(vector<vector<char>> & vLevel)
{
	// Display the initial state
	cout << "Initial state: " << endl;


	for( auto it = m_vvTiles.begin(); it != m_vvTiles.end(); it++ )
	{
		// Iterate the inner vector
		for( auto itInner = (*it).begin();
			itInner != (*it).end();
			itInner++ )
	    {
			cout << (*itInner);
		}

		// End of line as we just output a row
        //
		cout << endl;
	}

	cout << endl;

	int x = -1;
	int y = -1;

	// pick a starting position
	for( int i = 0; i < vLevel.size(); i++ )
	{
		for( int j = 0; j < vLevel[i].size(); j++ )
		{
			if( vLevel[i][j] == '.' || vLevel[i][j] == '#' )
			{
				// Starting position just has to be a room or
				// tunnel tile
				x = j;
				y = i;
                //count room tiles here...
			}
		}
	}

	if( x == -1 )
	{
		cout << "Unable to find starting position!" << endl;
		return false;
	}
	
	// Call the function which actually marks the tiles -- it should mark
	// the starting tile, then any adjacent to it, etc -- so after it's done,
	// everything that can be connected to the starting tile should be
	// marked.
	markPosition(vLevel, x, y);

	bool bCorrect = true;

	cout << endl << "Marked state: " << endl;
	// Outer loop
	for( auto itOuter = vLevel.begin(); itOuter != vLevel.end(); itOuter++ )
	{
		// Inner loop
		for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ )
		{
			cout << (*itInner);


			// Now, test if it's a room/tunnel tile -- if it's still
			// one after we've 
			if( (*itInner) == '.' || (*itInner) == '#' )
			{
				bCorrect = false;
			}
		}

		cout << endl;
	}

	cout << endl;

	if( !bCorrect )
	{
		cout << "Unreached room/tunnel tile detected!" << endl;
	}


	return bCorrect;
}
