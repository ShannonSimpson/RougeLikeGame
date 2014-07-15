//Scroll.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Scroll.h"
#include <iostream>

using namespace std;

Scroll::Scroll() : Consumable()
{
	//constructor
}

Scroll::~Scroll()
{
	//deconstructor
}

void Scroll::use()
{
}

void Scroll::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Scroll: " << endl;
	dumpObjectData();
}

void Scroll::dumpObjectData()
{
	//continue to dump of the object data onto the console
	Consumable::dumpObjectData();
}

void Scroll::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Scroll>" << endl;
	writeDataAsFragment(output);
	output << "  </Scroll>" << endl;
}

void Scroll::writeDataAsFragment(ostream & output)
{
	//will continue to write the data into the output file
	Consumable::writeDataAsFragment(output);
}

void Scroll::setElementData(string sElementName, string sValue)
{
	//continues to write the output in the output file
	Consumable::setElementData(sElementName, sValue);
}