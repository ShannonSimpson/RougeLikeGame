//Wand.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Wand.h"
#include <iostream>

using namespace std;

Wand::Wand() : Consumable()
{
	//constructor
}

Wand::~Wand()
{
	//deconstructor
}

void Wand::use()
{
}

void Wand::dumpObject()
{
	cout << endl;
	cout << "Wand: " << endl;
	dumpObjectData();
}

void Wand::dumpObjectData()
{
	//will begin the dump of the object onto the console
	Consumable::dumpObjectData();
}

void Wand::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Wand>" << endl;
	writeDataAsFragment(output);
	output << "  </Wand>" << endl;
}

void Wand::writeDataAsFragment(ostream & output)
{
	//continues to write the output in the output file
	Consumable::writeDataAsFragment(output);
}

void Wand::setElementData(string sElementName, string sValue)
{
	//dumps the member variables of the entity onto the console
	Consumable::setElementData(sElementName, sValue);
}