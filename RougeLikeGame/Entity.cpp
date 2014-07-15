//Entity.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity() : XMLSerializable()
{
	//A default name in case one is not given in the file
	m_sName = "Unnamed";
	
	//A default character in case one is not given in the file
	m_displayChar = '@';
}

Entity::~Entity()
{
	//deconstructor
}

string Entity::getName()
{
	//returns the name given in the file.
	return m_sName;
}

void Entity::setName(string sName)
{
	//sets the name given in the file to the memeber variable.
	m_sName = sName;
}

bool Entity::hasProperty()
{
	return true; //will probably change throughout program's evoultion
}

string Entity::getDescription(string sName)
{
	return 0; //will probably change throughout program's evolution
}

void Entity::setDisplayChar(char displayChar)
{
	// the character that will appear in place of the "person" on the board.
	m_displayChar = displayChar;
}

char Entity::getDisplayChar()
{
	//returns the character that is displayed for the person
	return m_displayChar;
}

void Entity::setCoords(int x, int y)
{
	m_y = y;
    m_x = x;
}

int Entity::getCoordX()
{
	return m_x;
}

int Entity::getCoordY()
{
	 return m_y;
}

void Entity::setProperty(string properties)
{
	m_properties.push_back(properties);
}

vector<string> Entity::getV()
{
	return m_properties;
}

void Entity::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Entity: " << endl;
	dumpObjectData();
}

void Entity::dumpObjectData()
{
	//dumps the member variables of the entity onto the console
	cout << "Individual Name: " << Entity::getName() << endl;
	cout << "Properties: ";
	for (size_t i = 0; i < m_properties.size(); i++)
	{
		// a loop for the properties since there can be more than one.
		cout << m_properties[i] << ", ";
	}
	cout << endl;
	cout << "Display Character: " << Entity::getDisplayChar() << endl;
}

void Entity::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "<Entity>" << endl;
	writeDataAsFragment(output);
	output << "</Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output)
{
	//calls the writeDataFragment on up the hierarchu
	XMLSerializable::writeDataAsFragment(output);

	//dumps the member variables of the entity into the output file
	output << "    <name>" << Entity::getName() << "</name>" << endl;
	output << "    <properties>" << endl;
	for (size_t i = 0; i < m_properties.size(); i++)
	{
		output << "      <property>" << m_properties[i] << "</property>" << endl;
	}
	output << "    </properties>" << endl;
	output << "    <displayChar>" << Entity::getDisplayChar() << "</displayChar>" << endl;
}

void Entity::setElementData(string sElementName, string sValue)
{
	// Set the value in between the tags to be value of that member variable's 
	if ( sElementName == "name" )
	{
		Entity::setName(sValue);
	}
	else if ( sElementName == "displayChar" )
	{
		Entity::setDisplayChar(sValue[0]);
	}
	else if ( sElementName == "property" )
	{
		Entity::setProperty(sValue);
	}
	else
	{
		XMLSerializable::setElementData( sElementName, sValue );
	}

}

