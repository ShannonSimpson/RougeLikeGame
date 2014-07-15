//Food.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Food.h"
#include <iostream>

using namespace std;

Food::Food() : Consumable()
{
	//constructor
}

Food::~Food()
{
	//deconstructor
}

void Food::use()
{
}

void Food::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Food: " << endl;
	dumpObjectData();
}

void Food::dumpObjectData()
{
	//continue to dump of the object data onto the console
	Consumable::dumpObjectData();
}

void Food::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Food>" << endl;
	writeDataAsFragment(output);
	output << "  </Food>" << endl;
}

void Food::writeDataAsFragment(ostream & output)
{
	//will continue to write the data into the output file
	Consumable::writeDataAsFragment(output);
}

void Food::setElementData(string sElementName, string sValue)
{
	//continues to write the output in the output file
	Consumable::setElementData(sElementName, sValue);
}