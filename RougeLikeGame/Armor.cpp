//Armor.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Armor.h"
#include <iostream>

using namespace std;

Armor::Armor() : Item()
{
	//A default for each member variables in case one is not given in the file
	m_ArmorValue = 0;
	m_sSlot = "No Slot";
	m_sArmorType = "No Armor Type";
}

Armor::~Armor()
{
	//deconstructor
}

void Armor::setSlot(string sSlot)
{
	//sets the slot given in the file to the member variable.
	m_sSlot = sSlot;
}

string Armor::getSlot()
{
	//gets the slot that was set.
	return m_sSlot;
}

void Armor::setArmorType(string sArmorType)
{
	//sets the armor type given in the file to the member variable.
	m_sArmorType = sArmorType;
}

string Armor::getArmorType()
{
	//gets the armor type that was set.
	return m_sArmorType;
}

void Armor::setArmorValue(int ArmorValue)
{
	//sets the armor value given in the file to the member variable.
	m_ArmorValue = ArmorValue;
}

int Armor::getArmorValue()
{
	//gets the armor value that was set.
	return m_ArmorValue;
}

void Armor::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Armor: " << endl;
	dumpObjectData();
}

void Armor::dumpObjectData()
{
	//will begin the dump of the object into the output file
	Item::dumpObjectData();

	cout << "Slot: " << Armor::getSlot() << endl;
	cout << "Type: " << Armor::getArmorType() << endl;
	cout << "Armor Value: " << Armor::getArmorValue() << endl;
}

void Armor::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Armor>" << endl;
	writeDataAsFragment(output);
	output << "  </Armor>" << endl;
}

void Armor::writeDataAsFragment(ostream & output)
{
	//Continues up the hierarchy and continue to write the data into the output file
	Item::writeDataAsFragment(output);

	//will continue to write the data into the output file
	if ( getSlot() != "No Slot" )
	{
		output << "    <slot>" << Armor::getSlot() << "</slot>" << endl;
	}
	if ( getArmorType() != "No Armor Type" )
	{
		output << "    <type>" << Armor::getArmorType() << "</type>" << endl;
	}
	if ( getArmorValue() != 0 )
	{
		output << "    <armorvalue>" << Armor::getArmorValue() << "</armorvalue>" << endl;
	}
}

void Armor::setElementData(string sElementName, string sValue)
{
	// Set the value in between the tags to be value of that member variable's 
	if ( sElementName == "slot" )
	{
		Armor::setArmorType(sValue);
	}
	else if ( sElementName == "type" )
	{
		Armor::setArmorType(sValue);
	}
	else if ( sElementName == "armorvalue" )
	{
		int iValue = atoi(sValue.c_str());
		Armor::setArmorValue(iValue);
	}
	else
	{
		//continues up the hierarchy to set the value in between the tags
		Item::setElementData(sElementName, sValue);
	}
}


