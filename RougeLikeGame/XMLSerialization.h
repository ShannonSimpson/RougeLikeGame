//XMLSerialization.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <fstream>
#include <string>

#ifndef _XMLSerialization_included_
#define _XMLSerialization_included_

class XMLSerialization
{
public:
	XMLSerialization();
	~XMLSerialization();

    virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

};

#endif