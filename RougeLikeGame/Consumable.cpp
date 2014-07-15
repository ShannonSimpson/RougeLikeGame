//Consumable.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Consumable.h"
#include <iostream>

using namespace std;

Consumable::Consumable() : Item()
{
	//A default for each member variables in case one is not given in the file
	m_iHealth = 0;
	m_iNutrition = 0;
}

Consumable::~Consumable()
{
	//deconstructor
}

void Consumable::use()
{
}

void use(int iHealth, int iNutrition)
{
}

void Consumable::setHealth(int iHealth)
{
	//gets the health that was set.
	m_iHealth = iHealth;
}

int Consumable::getHealth()
{
	//sets the health given in the file to the member variable.
	return m_iHealth;
}

void Consumable::setNutrition(int iNutrition)
{
	//sets the nutrition given in the file to the member variable.
	m_iNutrition = iNutrition;
}

int Consumable::getNutrition()
{
	//gets the nutrition that was set.
	return m_iNutrition;
}


void Consumable::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Consumable: " << endl;
	dumpObjectData();
}

void Consumable::dumpObjectData()
{
	//will begin the dump of the object into the output file
	Item::dumpObjectData();

	cout << "Health: " << Consumable::getHealth() << endl;
	cout << "Nutrition: " << Consumable::getNutrition() << endl;
}

void Consumable::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Consumable>" << endl;
	writeDataAsFragment(output);
	output << "  </Consumable>" << endl;
}

void Consumable::writeDataAsFragment(ostream & output)
{
	//Continues up the hierarchy and continue to write the data into the output file
	Item::writeDataAsFragment(output);

	//will continue to write the data into the output file
	if ( getHealth() != 0 )
	{
		output << "    <health>" << Consumable::getHealth() << "</health>" << endl;
	}
	if ( getNutrition() != 0 )
	{
		output << "    <nutrition>" << Consumable::getNutrition() << "</nutrition>" << endl;
	}
}

void Consumable::setElementData(string sElementName, string sValue)
{
	// Set the value in between the tags to be value of that member variable's 
	if ( sElementName == "health" )
	{
		int iValue = atoi(sValue.c_str());
		Consumable::setHealth(iValue);
	}
	else if ( sElementName == "nutrition" )
	{
		int iValue = atoi(sValue.c_str());
		Consumable::setNutrition(iValue);
	}
	else
	{
		//continues up the hierarchy to set the value in between the tags
		Item::setElementData(sElementName, sValue);
	}
}

