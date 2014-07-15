//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

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
#include "XMLSerialization.h"

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool parseElement(istream & input, XMLSerialization * pXMLSerialization, vector<XMLSerialization*> &vObjects);
bool parseXML(istream & input, vector<XMLSerialization*> &vObjects);
void outputXML(vector<XMLSerialization*> & vObjects, ostream & output);
void SpitOutOntoConsole(vector<XMLSerialization *> & vObjects);


//  returns a bool indicating success; false if invalid XML was encountered, true if the XML was parsed correctly
//
// arguments:
//   istream & input - an input stream of the XML file being processed
//
//   string sHierarchy - the current position in the XML document's object hierarchy which is 
//   being processed
//	
// note: this does *not* properly check for end of input in the XML document!
//
// This function assumes that we are on the first character AFTER the opening <.
bool parseElement(istream & input, XMLSerialization * pXMLSerialization, vector<XMLSerialization*> &vObjects)
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
		pXMLSerialization = new Entity;
		vObjects.push_back(pXMLSerialization);
	}
	else if(sEleName == "Item")
	{
		pXMLSerialization = new Item;
		vObjects.push_back(pXMLSerialization);
	}
	else if(sEleName == "Creature")
	{
		pXMLSerialization = new Creature;
		vObjects.push_back(pXMLSerialization);
	}
	else if( sEleName == "Weapon")
	{
		pXMLSerialization = new Weapon;
		vObjects.push_back(pXMLSerialization);
	}
	else if( sEleName == "Armor" )
	{
		pXMLSerialization = new Armor;
		vObjects.push_back(pXMLSerialization);
	}
	else if(sEleName == "Consumable" )
	{
		pXMLSerialization = new Consumable;
		vObjects.push_back(pXMLSerialization);
	}
	else if (sEleName == "Potion")
	{
		pXMLSerialization = new Potion;
		vObjects.push_back(pXMLSerialization);
	}
	else if (sEleName == "Scroll")
	{
		pXMLSerialization = new Scroll;
		vObjects.push_back(pXMLSerialization);
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
				pXMLSerialization->setElementData(sEleName, sContent);
				// And since we have fully parsed an element, we return to whatever called us in the first place
				return true;

			}
			else
			{
				// In this branch, we have already read in a <, but it was NOT an end tag -- the input file is currently positioned on the first character
				// after the opening <, so we can call parseElement on it...
				//
				// Here we're passing the hierarchy we know plus the current element name, so this next element knows where it is in the overal document hiearchy
				if( !parseElement(input, pXMLSerialization, vObjects) )
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

// parseXML -- parses an XML document.  First it makes a very half-hearted check for the validity of the XML header, then it parses the root element of the document.
bool parseXML(istream & input, vector<XMLSerialization*> &vObjects)
{
	char c;

	//A function pointer pointing to XMLSerialization
	XMLSerialization * pXMLSerialization = NULL;

	// Read in the XML, one character at a time, until we hit a <.
	do
	{
		c = input.get();
	} while( c != '<' );
	
	// Check the character after the < -- if it's not a ?, we aren't seeing a valid XML header
	if( input.get() !='?' )
	{
		cout << "Invalid XML Header." << endl;
		return false;
	}

	// Burn off the rest of the header, looking for a ?
	do
	{
		c = input.get();
	} while( c != '?' );

	// Then we check for a > -- which tests for the header ending with ?>
	if( input.get() != '>' )
	{
		cout << "Invalid XML header" << endl;
		return false;
	}

	// Now burn off characters until we get to the first tag after the XML header...
	do
	{
		c = input.get();
	} while( c != '<' );
	
	//variable to hold the temporary character
	string temp;

	//just to look at the next character without taking it.
	while( input.peek() != '>')
	{
		//if next character is not the end of the tag, the temp variable is gathered
		c= input.get();
		temp.push_back(c);
	}
	if(temp != "World")
	{
		//XML must end in WORLD
		cout << "This isn't our kind of XML Document. Incorrect tags." << endl;
	}
	while(true)
	{
		do
		{
			c = input.get();
		}
		while ( c != '<');
		if(input.peek() == '/')
		{
			cout << "An XML Document was Successfully Loaded." << endl << "World Loaded:" << endl;
			return true;
		}
		if( c == '<')
		{
			parseElement(input, pXMLSerialization, vObjects);
		}
	}
}

void outputXML(vector<XMLSerialization*> & vObjects, ostream & output)
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

//runs through all the dump objects to display onto console.
void SpitOutOntoConsole(vector<XMLSerialization *> & vObjects)
{
	for(size_t i = 0 ; i < vObjects.size() ; i++)
	{
		vObjects[i]->dumpObject();
	}
}

int main()
{
	//variables to hold the input that tells where the file is
	string file; 
	ifstream input;
	do
	{
		//reads in and opens the file requested
		cout << "Enter a filename with .xml exstension: ";
		cin >> file;
		cout << endl;
		input.open(file.c_str());
		if(!input.good()) //if the file is not good...
		{
			cout << "No file by that name. Try Again. " << endl;
		}
	} while(!input.good()); //continue to spit out the same comment until it is good.

	//the vector to hold the objects of the world
	vector<XMLSerialization*> vObjects;

	//parse through the file
	parseXML(input, vObjects);

	//display the file onto the console
	SpitOutOntoConsole(vObjects);
	
	string outFile;
	ofstream output;	

	cout << endl << endl << "What is the output file going to be named? " ;
	cout << endl;
	cin >> outFile;

	output.open(outFile);
	
	//output the read in file back out into the output file in XML format
	outputXML(vObjects, output);

	//deletes the world vector.
	for(size_t i = 0; i < vObjects.size() ; i++)
	{
		delete vObjects[i];
	}

	//closes open files
	input.close();
	output.close();

	return 0;
}