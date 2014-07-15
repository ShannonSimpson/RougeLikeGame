//Scroll.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Consumable.h"

#ifndef _Scroll_included_
#define _Scroll_included_

class Scroll:public Consumable
{
public:
	Scroll(); //Constructor
	virtual ~Scroll(); //Destructor

	virtual void use();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
}; 







#endif