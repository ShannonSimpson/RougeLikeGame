//Armor.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Item.h"

#ifndef _Armor_included_
#define _Armor_included_

class Armor: public Item
{
public:
	Armor(); //Constructor
	virtual ~Armor(); //Destructor

	//Getters and Setters
	virtual void setSlot(std::string sSlot);
	virtual std::string getSlot();
	virtual void setArmorType(std::string sArmorType);
	virtual std::string getArmorType();
	virtual void setArmorValue(int ArmorValue);
	virtual int getArmorValue();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private:
	std::string m_sSlot;
	std:: string m_sArmorType;
	int m_ArmorValue;
};

#endif