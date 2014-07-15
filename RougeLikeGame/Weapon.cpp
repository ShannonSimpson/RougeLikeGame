//Weapon.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include "Weapon.h"
#include "Item.h"
#include <iostream>

using namespace std;

Weapon::Weapon() : Item()
{
	//A default for each member variables in case one is not given in the file
	m_iDamage = 0;
	m_iAccuracy = 0;
	m_lRange = 0;
	m_sWeaponType = "No Weapon Type";
	m_AmmoType = "No Ammo Type";
}

Weapon::~Weapon()
{
	//deconstructor
}

void Weapon::setDamage(int iDamage)
{
	//sets the Damage given in the file to the member variable.
	m_iDamage = iDamage;
}

int Weapon::getDamage()
{
	//gets the damage that was set.
	return m_iDamage;
}

void Weapon::setWeaponType(string sWeaponType)
{
	//sets the weapon type given in the file to the member variable.
	m_sWeaponType = sWeaponType;
}
	
string Weapon::getWeaponType()
{
	//gets the weapon type that was set.
	return m_sWeaponType;
}
	
void Weapon::setAccuracy(int iAccuracy)
{
	//sets the accuracy given in the file to the member variable.
	m_iAccuracy = iAccuracy;
}

int Weapon::getAccuracy()
{
	//gets the accuracy that was set.
	return m_iAccuracy;
}

void Weapon::setRange(long lRange)
{
	//sets the range given in the file to the member variable.
	m_lRange = lRange;
}
	
long Weapon::getRange()
{
	//gets the range that was set
	return m_lRange;
}
	
void Weapon::setAmmoType(string AmmoType)
{
	//sets the ammo type given in the file to the member variable.
	m_AmmoType = AmmoType;
}

string Weapon::getAmmoType()
{
	//gets the ammo type that was set.
	return m_AmmoType;
}

void Weapon::dumpObject()
{
	//will begin the dump of the object onto the console
	cout << endl;
	cout << "Weapon: " << endl;
	dumpObjectData();
}

void Weapon::dumpObjectData()
{
	//will begin the dump of the object into the output file
	Item::dumpObjectData();

	cout << "Damage: " << Weapon::getDamage() << endl;
	cout << "Type: " << Weapon::getWeaponType() << endl;
	cout << "Accuracy: " << Weapon::getAccuracy() << endl;
	cout << "Range: " << Weapon::getRange() << endl;
	cout << "AmmoType: " << Weapon::getAmmoType() << endl;
}

void Weapon::writeFragment(ostream & output)
{
	//will begin the dump of the object into the output file
	output << endl;
	output << "  <Weapon>" << endl;
	writeDataAsFragment(output);
	output << "  </Weapon>" << endl;
}

void Weapon::writeDataAsFragment(ostream & output)
{
	//Continues up the hierarchy and continue to write the data into the output file
	Item::writeDataAsFragment(output);

	if (getDamage() != 0 )
	{
		output << "    <damage>" << getDamage() << "</damage>" << endl;
	}
	if (getWeaponType() != "No Weapon Type")
	{
		output << "    <weapontype>" << getWeaponType() << "</weapontype>" << endl;
	}
	if (getAccuracy() != 0)
	{
		output << "    <accuracy>" << getAccuracy() << "</accuracy>" << endl;
	}
	if (getRange() != 0)
	{
		output << "    <range>" << getRange() << "</range>" << endl;
	}
	if (getAmmoType() != "No Ammo Type")
	{
		output << "    <ammotype>" << getAmmoType() << "</ammotype>" << endl;
	}
}

void Weapon::setElementData(string sElementName, string sValue)
{
	// Set the value in between the tags to be value of that member variable's 
	if ( sElementName == "damage" )
	{
		int iValue = atoi(sValue.c_str());
		Weapon::setDamage(iValue);
	}
	else if ( sElementName == "weapontype" )
	{
		Weapon::setWeaponType(sValue);
	}
	else if ( sElementName == "accuracy" )
	{
		int iValue = atoi(sValue.c_str());
		Weapon::setAccuracy(iValue);
	}
	else if ( sElementName == "range" )
	{
		int lValue = atol(sValue.c_str());
		Weapon::setRange(lValue);
	}
	else if ( sElementName == "ammotype" )
	{
		Weapon::setAmmoType(sValue);
	}
	else
	{
		//continues up the hierarchy to set the value in between the tags
		Item::setElementData(sElementName, sValue);
	}
}