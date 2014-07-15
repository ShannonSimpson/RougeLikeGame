//Wand.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef _Wand_included_
#define _Wand_included_

class Wand:public Consumable
{
public:
	Wand(); //Constructor
	virtual ~Wand(); //Destructor

	virtual void use();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
}; 

#endif
