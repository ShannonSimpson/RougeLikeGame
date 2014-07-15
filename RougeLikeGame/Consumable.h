//Consumable.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Item.h"

#ifndef _Consumable_included_
#define _Consumable_included_

class Consumable:public Item
{
public:
	Consumable(); //Constructor
	virtual ~Consumable(); //Destructor

	virtual void use();

	//Getters and Setters
	virtual void setHealth(int iHealth);
	virtual int getHealth();
	virtual void setNutrition(int iNutrition);
	virtual int getNutrition();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
	int m_iHealth;
	int m_iNutrition;

}; 







#endif