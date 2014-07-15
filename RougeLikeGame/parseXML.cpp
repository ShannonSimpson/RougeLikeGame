//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

//parseXML function
// parseXML -- parses an XML document.  First it makes a very half-hearted check for the validity of the XML header, then it parses the root element of the document.
//bool parseXML(istream & input, vector<XMLSerializable*> &vObjects)

#include "parseXML.h"
#include "XMLSerializable.h"

#include <vector>
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// parseXML -- parses an XML document.  First it makes a very half-hearted check for the validity of the XML header, then it parses the root element of the document.
bool parseXML(istream & input, vector<XMLSerializable*> &vObjects)
{
	char c;

	//A function pointer pointing to XMLSerializable
	XMLSerializable * pXMLSerializable = NULL;

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
	//if(temp != "World")
	//{
	//	//XML must end in WORLD
	//	cout << "This isn't our kind of XML Document. Incorrect tags." << endl;
	//}
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
			parseElement(input, pXMLSerializable, vObjects);
		}
	}
}