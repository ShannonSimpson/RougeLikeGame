//Ammo.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Item.h"
#include <cstdlib>

#ifndef _Ammo_included_
#define _Ammo_included_


class Ammo: public Item
{
public:
	Ammo(); //Constructor
	virtual ~Ammo(); //Destructor

	//Getters and Setters
	virtual int getDamageBonus();
	virtual void setDamageBonus(int iDamageBonus);
	virtual std::string getType();
	virtual void setType(std::string sType);

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private:
	int m_iDamageBonus;
	std::string m_sType;

};

#endif