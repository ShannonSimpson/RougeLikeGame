//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

//OutputXML function
//void outputXML(vector<XMLSerializable*> & vObjects, ostream & output)

#include "Ammo.h"
#include "Entity.h"
#include "Item.h"
#include "Armor.h"
#include "Consumable.h"
#include "Creature.h"
#include "Food.h"
#include "Gold.h"
#include "Potion.h"
#include "Scroll.h"
#include "SpellBook.h"
#include "Wand.h"
#include "Weapon.h"
#include "XMLSerializable.h"

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void outputXML(vector<XMLSerializable*> & vObjects, ostream & output)
{
	// Write the XML header to the output
	output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;

	// Write the opening World tag (as an XML document needs a root element to be valid)
	output << "<World>" << endl;

	// And iterate through the vector of objects...for( int i = 0, i < vObjects.size(); i++))
	for( auto it = vObjects.begin(); 
		it != vObjects.end();
		it++ )
	{
		(*it)->writeFragment(output);
		cout << endl;
	}

	// And output the end tag for the root  element.
	output << "</World>" << endl;
}