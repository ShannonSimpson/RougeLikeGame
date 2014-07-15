//Potion.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Potion.h"
#include <iostream>

using namespace std;

Potion::Potion() : Consumable()
{
	//constructor
}

Potion::~Potion()
{
	//deconstructor
}

void Potion::use()
{
}

void Potion::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Potion: " << endl;
	dumpObjectData();
}

void Potion::dumpObjectData()
{
	//continue to dump of the object data onto the console
	Consumable::dumpObjectData();
}

void Potion::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Potion>" << endl;
	writeDataAsFragment(output);
	output << "  </Potion>" << endl;
}

void Potion::writeDataAsFragment(ostream & output)
{
	//will continue to write the data into the output file
	Consumable::writeDataAsFragment(output);
}

void Potion::setElementData(string sElementName, string sValue)
{
	//continues to write the output in the output file
	Consumable::setElementData(sElementName, sValue);
}