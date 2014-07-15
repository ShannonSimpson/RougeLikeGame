//XMLSerializable.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <fstream>
#include <string>

#ifndef _XMLSerializable_included_
#define _XMLSerializable_included_

class XMLSerializable
{
public:
	XMLSerializable();
	~XMLSerializable();

    virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

};

#endif