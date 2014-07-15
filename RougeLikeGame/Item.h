//Item.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3

//
#ifndef _Item_included_
#define _Item_included_
#include "Entity.h"
#include <iostream>

//class: item
class Item : public Entity
{
public:
//constructor and destructor
	Item();
	virtual ~Item();
//getters and setters
	virtual void setItemWeight(int itemWeight);
	virtual int getItemWeight();
	virtual void setValue(int value);
	virtual int getValue();
	virtual void setRarity(int rarity);
	virtual int getRarity();
	virtual void setEnchantment(int enchantment);
	virtual int getEnchantment();
	virtual void setQuantity(int quantity);
	virtual int getQuantity();	
//stuff from XMLSerializable
	virtual void pickUp();
	virtual std::string getDescription();
    virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);                
	virtual void setElementData(std::string elementName, std::string Value);	



private:
	int m_itemWeight;
	int m_value;
	int m_rarity;
	int m_enchantment;
	int m_quantity;
};

#endif
