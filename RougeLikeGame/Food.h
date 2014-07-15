//Food.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Consumable.h"
#include <iostream>

#ifndef _Food_included_
#define _Food_included_

class Food:public Consumable
{
public:
	Food(); //Constructor
	virtual ~Food(); //Destructor

	virtual void use();
	
	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);


private: 
}; 







#endif