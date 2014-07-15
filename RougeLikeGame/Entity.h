//Entity.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <string>
#include <vector>
#include "XMLSerializable.h"

#ifndef _Entity_included_
#define _Entity_included_

class Entity:public XMLSerializable
{
public:
	Entity(); //Constructor
	virtual ~Entity(); //Destructor

	//Getters and Setters
	virtual std::string getName();
	virtual void setName(std::string sName);
	virtual void setDisplayChar(char displayChar);
	virtual char getDisplayChar();
	virtual void setCoords(int x, int y);
    virtual int getCoordX();
	virtual int getCoordY();

	virtual std::string getDescription(std::string Character);

	virtual void setProperty(std::string properties);
	virtual std::vector<std::string> getV();

	virtual bool hasProperty();

	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private:
	std::string m_sName;
	char m_displayChar;
	std::vector<std::string> m_properties;

	int m_y;
    int m_x;
};




#endif