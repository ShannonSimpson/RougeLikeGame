//Shannon Simpson
//Shannon.Simpson@uky.edu
//Program 1-3

#ifndef _DungeonLevel_included_
#define _DungeonLevel_included_

#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include "Tile.h"
#include "Creature.h"


//building a DungeonLevel class that creates a random Dungeon, creates tunnels, and checks to see if the dungeon follows through with specs
class DungeonLevel
{
public:
	DungeonLevel(int iWidth, int iHeight);
	virtual ~DungeonLevel();
	virtual int display(int x, int y);
    virtual int randomSidePick(int x1, int y1, int x2, int y2, std::mt19937 & mt);
    virtual void digTunnel(std::vector<std::vector<char>> & m_vvTiles, int doorX, int doorY, int mainTunnelX);
	void markPosition(std::vector<std::vector<char>> & vLevel, int x, int y);
    bool testLevel(std::vector<std::vector<char>> &  vLevel);
    int upstairXCoord();
    int upstairYCoord();
    int downstairXCoord();
    int downstairYCoord();
    virtual bool checkMove(int x, int y);
    virtual bool checkCreature(int x, int y);
    virtual bool checkItem(int x, int y);
    virtual void setCreature(Creature * pThing, int x, int y);
    virtual Creature * getCreature(int x, int y);
    virtual void removeCreature(int x, int y);
    virtual void setItems(Item * pItem, int x, int y);
	virtual void pickUpItem(int x, int y);

private:
	std::vector<std::vector<char>> m_vvTiles;

    std::vector<std::vector<Tile*>> m_vvNewTiles;
    
    std::vector<int> m_vvDoorCoords;
    std::vector<std::vector<bool>> m_vvTileBools;
    bool occupied;
	bool Section0;
	bool Section1;
	bool Section2;
	bool Section3;
	bool Section4;
	bool Section5;
	bool collideCheck;

    bool top;
    bool left;
    bool bottom;
    bool right;

    bool side;

    int randomSide;
    int randomX;
    int randomY;

    int tunnelX;
    int tunnelY;
    int num;

	int sectNum;
    int sectNumTemp;
	int iStartX;
	int iStartY;
	int iRandomHeight;
	int iRandomWidth;
	int tileCount;

    int m_upstairsX;
    int m_upstairsY;

    int m_downstairsX;
    int m_downstairsY;

};
extern std::mt19937 mt;

#endif
