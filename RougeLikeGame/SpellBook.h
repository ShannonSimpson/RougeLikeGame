//SpellBook.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Consumable.h"

#ifndef _SpellBook_included_
#define _SpellBook_included_

class SpellBook:public Consumable
{
public:
	SpellBook(); //Constructors
	virtual ~SpellBook(); //Destructors

	virtual void use();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
}; 







#endif