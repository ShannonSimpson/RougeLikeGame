//Item.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//Program 1-3


#include "Item.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Item constructor
Item::Item()
{
	m_itemWeight = 0;
	m_value = 0;
	m_rarity = 0;
	m_enchantment = 0;
	m_quantity = 0;
}
//Item destructor
void Item::setItemWeight(int itemWeight)
{
	m_itemWeight = itemWeight;
}
//getters and setters
int Item::getItemWeight()
{
	return m_itemWeight;
}

void Item::setValue(int value)
{
	m_value = value;
}

int Item::getValue()
{
	return m_value;
}

void Item::setRarity(int rarity)
{
	m_rarity = rarity;	
}

int Item::getRarity()
{
	return m_rarity;
}

void Item::setEnchantment(int enchantment)
{
	m_enchantment = enchantment;
}

int Item::getEnchantment()
{
	return m_enchantment;
}

void Item::setQuantity(int quantity)
{
	m_quantity = quantity;
}

int Item::getQuantity()
{
	return m_quantity;
}

// Item deconstructor
Item::~Item()
{

}

// pickUp
void Item::pickUp()
{

}

// getDescription
string Item::getDescription()
{
	return 0;
}
//dumps object
void Item::dumpObject()
{
	cout << "Item: " << endl;
	dumpObjectData();
}
//dumps objects data
void Item::dumpObjectData()
{
	cout << " - Item Weight =  " << getItemWeight() << endl;
	cout << " - Value = " << getValue() << endl;
	cout << " - Rarity = " << getRarity() << endl;
	cout << " - Enchantment = " << getEnchantment() << endl;
	cout << " - Quantity = " << getQuantity() << endl;
	Entity::dumpObjectData();
}
// write object as xml
void Item::writeFragment(ostream & output)
{
	output << "\t <Item>" << endl;
	writeDataAsFragment(output);
	output << "\t </Item>" << endl;
}
//write objects data as xml
void Item::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);
	output << "\t \t <weight>" << getItemWeight() << "</weight>" << endl;
	output << "\t \t <value>" << getValue() << "</value>" << endl;
	output << "\t \t <rarity>" << getRarity() << "</rarity>" << endl;
	output << "\t \t <enchantment>" << getEnchantment() << "</enchantment>" << endl;
	output << "\t \t <quantity>" << getQuantity() << "</quantity>" << endl;
}
//set elements data
void Item::setElementData(string elementName, string Value)
{
	if(elementName == "weight")
	{
		int number = atoi(Value.c_str());
		setItemWeight(number);
	}
	else if(elementName == "value")
	{
		int number = atoi(Value.c_str());
		setValue(number);
	}
	else if(elementName == "rarity" )
	{
		int number = atoi(Value.c_str());
		setRarity(number);
	}
	else if(elementName == "enchantment")
	{
		int number = atoi(Value.c_str());
		setEnchantment(number);
	}
	else if(elementName == "quantity")
	{
		int number = atoi(Value.c_str());
		setEnchantment(number);
	}
	else
	{
		Entity::setElementData(elementName, Value);
	}
}
