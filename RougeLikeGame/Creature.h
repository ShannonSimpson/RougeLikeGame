//Creature.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3


#ifndef CREATURE_H
#define CREATURE_H
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

class Creature : public Entity
{
public:
	Creature();
	virtual ~Creature();

	virtual void setLevel(int level);
	virtual int getLevel();
	virtual void setHP(int HP);
	virtual int getHP();
	virtual void setMaxHP(int maxHP);
	virtual int getMaxHP();
	virtual void setInventory(Item * pItem);
	virtual void getInventory();

    virtual Item * getDropItem();
    virtual void setDropItem();

    virtual void attemptMove(); 

    virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string elementName, std::string Value);

    virtual void setWeapon(Weapon * pWeapon);
    virtual Weapon * getWeapon();

    virtual void setArmorType(Armor * pArmor);
    virtual Armor * getArmorType();

private:
    Weapon * m_pWeapon;
    Armor * m_pArmor;
	int m_level;
	int m_HP;
	int m_maxHP;
    Item * pItem;
    Item * pItemDrop;
	std::vector<Item*> inventory;
};

#endif 
