//Ammo.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Ammo.h"

#include <iostream>

using namespace std;

Ammo::Ammo() : Item()
{
	//A default for each member variables in case one is not given in the file
	m_iDamageBonus = 0;
	m_sType = "No Type";
}

Ammo::~Ammo()
{
	//deconstructor
}

int Ammo::getDamageBonus()
{
	//gets the damage bonus that was set.
	return m_iDamageBonus;
}

void Ammo::setDamageBonus(int iDamageBonus)
{
	//sets the damage bonus given in the file to the member variable.
	m_iDamageBonus = iDamageBonus;
}

string Ammo::getType()
{
	//sets the type that was set.
	return m_sType;
}

void Ammo::setType(string sType)
{
	//sets the type given in the file to the member variable.
	m_sType = sType;
}

void Ammo::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Ammunition: " << endl;
	dumpObjectData();
}

void Ammo::dumpObjectData()
{
	//will begin the dump of the object into the output file
	Item::dumpObjectData();

	cout << "Damage Bonus: " << Ammo::getDamageBonus() << endl;
	cout << "Type: " << Ammo::getType() << endl;
}

void Ammo::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Ammo>" << endl;
	writeDataAsFragment(output);
	output << "  </Ammo>" << endl;
}

void Ammo::writeDataAsFragment(ostream & output)
{
	//Continues up the hierarchy and continue to write the data into the output file
	Item::writeDataAsFragment(output);

	//will continue to write the data into the output file
	if (getDamageBonus() != 0)
	{
		output << "    <damagebonus>" << Ammo::getDamageBonus() << "</damagebonus>" << endl;
	}
	if (getType() != "No Type")
	{
		output << "    <type>" << Ammo::getType() << "</type>" << endl;
	}
}

void Ammo::setElementData(string sElementName, string sValue)
{
	// Set the value in between the tags to be value of that member variable's 
	if ( sElementName == "damagebonus" )
	{
		int iValue = atoi(sValue.c_str());
		Ammo::setDamageBonus(iValue);
	}
	else if ( sElementName == "HP" )
	{
		Ammo::setType(sValue);
	}
	else
	{
		//continues up the hierarchy to set the value in between the tags
		Item::setElementData(sElementName, sValue);
	}
}