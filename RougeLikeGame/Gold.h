//Gold.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Item.h"

#ifndef _Gold_included_
#define _Gold_included_

class Gold:public Item
{
public:
	Gold(); //Constructor
	virtual ~Gold(); //Destructor

	virtual void pickup();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private: 
}; 







#endif