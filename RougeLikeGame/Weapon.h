//Weapon.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include "Item.h"

#ifndef _Weapon_included_
#define _Weapon_included_


class Weapon:public Item
{
public:
	Weapon(); //Constructor
	virtual ~Weapon(); //Destructor

	//Getters and Setters
	virtual void setDamage(int iDamage);
	virtual int getDamage();
	virtual void setWeaponType(std::string sWeaponType);
	virtual std::string getWeaponType();
	virtual void setAccuracy(int iAccuracy);
	virtual int getAccuracy();
	virtual void setRange(long lRange);
	virtual long getRange();
	virtual void setAmmoType(std::string AmmoType);
	virtual std::string getAmmoType();


	virtual void dumpObject();
    virtual void dumpObjectData();
    virtual void writeFragment(std::ostream & output);
    virtual void writeDataAsFragment(std::ostream & output);
    virtual void setElementData(std::string sElementName, std::string sValue);

private:
	int m_iDamage;
	std::string m_sWeaponType;
	int m_iAccuracy;
	long m_lRange;
	std::string m_AmmoType;
};

#endif