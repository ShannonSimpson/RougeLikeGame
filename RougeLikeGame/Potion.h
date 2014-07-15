//Potion.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Consumable.h"

#ifndef _Potion_included_
#define _Potion_included_


class Potion:public Consumable
{
public:
	Potion(); //Constructor
	virtual ~Potion(); //Destructor

	virtual void use();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
}; 

#endif