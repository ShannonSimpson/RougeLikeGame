//Tile.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3

#ifndef _Tile_included_
#define _Tile_included_

#include "Entity.h"
#include "Creature.h"
#include "Item.h"
#include "ItemFactory.h"
#include <vector>

class Tile
{
public:
    Tile(char c, bool stopWalking);
    virtual ~Tile();
    virtual char tileDisplayChar();
    virtual bool returnBool();
    virtual bool returnCreatureBool();
    virtual bool returnItemBool();
    virtual Creature * getCreature();
    virtual void setCreature(Creature * onlyCreature);
    virtual void removeCreature();
    virtual void setItems(Item * pItem);
    virtual void pickUpItem();


private:
    char m_c;
    std::vector<Item*> Items;
    Creature * m_onlyCreature;
    bool m_stopWalking;
    bool bCreature;
    bool bItem;
};

#endif
