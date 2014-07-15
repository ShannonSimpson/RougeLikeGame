//Gold.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Gold.h"
#include <iostream>

using namespace std;

Gold::Gold() : Item()
{
	//constructor
}

Gold::~Gold()
{
	//deconstructor
}

void Gold::pickup()
{
}

void Gold::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Gold: " << endl;
	dumpObjectData();
}

void Gold::dumpObjectData()
{
	//continue to dump of the object data onto the console
	Item::dumpObjectData();
}

void Gold::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Gold>" << endl;
	writeDataAsFragment(output);
	output << "  </Gold>" << endl;
}

void Gold::writeDataAsFragment(ostream & output)
{
	//will continue to write the data into the output file
	Item::writeDataAsFragment(output);
}

void Gold::setElementData(string sElementName, string sValue)
{
	//continues to write the output in the output file
	Item::setElementData(sElementName, sValue);
}