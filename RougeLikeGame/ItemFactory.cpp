//ItemFactory.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3

#include "ItemFactory.h"
#include "parseXML.h"
#include <fstream>
#include <ctime>


using namespace std;

ItemFactory & ItemFactory::instance()
{
	// Dummy, just to make this compile -- won't work.
	//return * static_cast<CreatureFactory*>(NULL);
	
	//set up class as a singleton
	static ItemFactory factory;

	return factory;

}

ItemFactory::ItemFactory()
{
	ifstream input;
	input.open("items.xml");

	vector<XMLSerializable*> vItem;
	parseXML(input, vItem);	
	
	input.close();
	
	for( auto it = vItem.begin(); it != vItem.end();it++)
	{
		Item * pItem = dynamic_cast<Item*>(*it);
		//dynamic cast makes sure object being pointed to is a creature, 
		//else it returns null.
		
		if( pItem != NULL )
		{
			m_vItems.push_back(pItem);
		}
	}
}

ItemFactory::~ItemFactory()
{
}

Item * ItemFactory::generateItem( int value )
{
	vector<Item*> vValidItems;

	for(auto it = m_vItems.begin(); it != m_vItems.end(); it++)
	{
		Item * pItem = * it;
		
		//modify this for loop and make it work for item, don't use iMaxLevel
		if(pItem->getValue() <= value)
		{	
			vValidItems.push_back(pItem);
		}
	}	

	if( vValidItems.size() == 0)
		return NULL;
	
	int iIndex = mt() % vValidItems.size();

	Item * pItems = vValidItems[iIndex];

	Item * pReturnValue = new Item(*pItems);
	

	return pReturnValue;
}
