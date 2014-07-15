//SpellBook.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "SpellBook.h"
#include <iostream>

using namespace std;

SpellBook::SpellBook() : Consumable()
{
	//constructor
}

SpellBook::~SpellBook()
{
	//deconstructor
}

void SpellBook::use()
{
}

void SpellBook::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "SpellBook: " << endl;
	dumpObjectData();
}

void SpellBook::dumpObjectData()
{
	//continue to dump of the object data onto the console
	Consumable::dumpObjectData();
}

void SpellBook::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <SpellBook>" << endl;
	writeDataAsFragment(output);
	output << "  </SpellBook>" << endl;
}

void SpellBook::writeDataAsFragment(ostream & output)
{
	//will continue to write the data into the output file
	Consumable::writeDataAsFragment(output);
}

void SpellBook::setElementData(string sElementName, string sValue)
{
	//continues to write the output in the output file
	Consumable::setElementData(sElementName, sValue);
}