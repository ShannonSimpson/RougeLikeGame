//Player.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA3

#ifndef _Player_included_
#define _Player_included_

#include "Entity.h"
#include "Item.h"
#include "Creature.h"
#include "DungeonLevel.h"

class Player : public Creature
{
public:
    Player();
    virtual ~Player();

    virtual int getScore();
    virtual void setScore(int score);
    virtual int getExperience();
    virtual void setExperience(int xp);
   
/*	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string elementName, std::string Value);	
*/
private:
    int m_score;
    int m_xp;
    char character;
    int startHP;
    int playerCoordX;
    int playerCoordY;
};


#endif