//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

//parseElement function
//bool parseElement(istream & input, XMLSerializable * pXMLSerializable, vector<XMLSerializable*> &vObjects)


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

bool parseElement(istream & input, XMLSerializable * pXMLSerializable, vector<XMLSerializable*> &vObjects)
{
	// char to hold data as we process it
	char c;

	// The name of the element; initialized to an empty string (as all strings are by default); we get this by reading in the XML
	string sEleName;

	// Read in the XML one character at a time, checking for the > at the end of the tag
	do
	{
		// Get the character off the stream		
		c = input.get();

		// If it's not the end tag, add it to the element name
		if( c != '>' )
		{
			sEleName.push_back(c);
		}

	} 
	while( c != '>' );

	// Holds the non-element content of the element
	string sContent;

	//each new object that comes through the file will be added to the objects vector.
	if(sEleName == "Entity")
	{
		pXMLSerializable = new Entity;
		vObjects.push_back(pXMLSerializable);
	}
	else if(sEleName == "Item")
	{
		pXMLSerializable = new Item;
		vObjects.push_back(pXMLSerializable);
	}
	else if(sEleName == "Creature")
	{
		pXMLSerializable = new Creature;
		vObjects.push_back(pXMLSerializable);
	}
	else if( sEleName == "Weapon")
	{
		pXMLSerializable = new Weapon;
		vObjects.push_back(pXMLSerializable);
	}
	else if( sEleName == "Armor" )
	{
		pXMLSerializable = new Armor;
		vObjects.push_back(pXMLSerializable);
	}
	else if(sEleName == "Consumable" )
	{
		pXMLSerializable = new Consumable;
		vObjects.push_back(pXMLSerializable);
	}
	else if (sEleName == "Potion")
	{
		pXMLSerializable = new Potion;
		vObjects.push_back(pXMLSerializable);
	}
	else if (sEleName == "Scroll")
	{
		pXMLSerializable = new Scroll;
		vObjects.push_back(pXMLSerializable);
	}
	
	while(true)
	{
		// Read a character off the stream
		c = input.get();

		// The important thing is to check to see if it is an open angled bracket.
		if( c == '<' )
		{
			if( input.peek() == '/' )
			{
			// If it is, we have two possibilities (assuming the XML is valid):
			// Either this is the start tag for a new element contained in the current element, or it's the end tag for our current element.
			// Note that if it is an end tag -- and the XML is valid -- it MUST be the end tag of the current element as elements are not allowed to overlap.
				input.get();

				// We must burn off the / since we only peeked it, and haven't gotten it yet!
				string sEndTag;

				//checks for end of tag
				do
				{
					c = input.get();
					if( c != '>' )
					{ 
						sEndTag.push_back(c);
					}
				} 
				while( c != '>' );

				// Now, we test for the validity of the XML -- the end tag's name must match the element's name...
				if( sEndTag != sEleName )
				{
					cout << "Tag name mismatch" << endl;
					return false;
				}

				//allows the ability the pass the functions as a parameter to other functions.
				pXMLSerializable->setElementData(sEleName, sContent);
				// And since we have fully parsed an element, we return to whatever called us in the first place
				return true;

			}
			else
			{
				// In this branch, we have already read in a <, but it was NOT an end tag -- the input file is currently positioned on the first character
				// after the opening <, so we can call parseElement on it...
				//
				// Here we're passing the hierarchy we know plus the current element name, so this next element knows where it is in the overal document hiearchy
				if( !parseElement(input, pXMLSerializable, vObjects) )
					return false;
			}
		}

		else
		{
			// In this branch, we have read in a character inside the element which is not a < -- since it's not part of an interior element, it's content, so
			// we add it to our variable which stores the content (ignoring end-of-line characters).
			if( c != '\n' )
				sContent.push_back(c);
		}
	}


	return true;
}
