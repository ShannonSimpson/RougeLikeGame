//Creature.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3


#include "Creature.h"

using namespace std;

// Creature constructor
Creature::Creature()
{
    m_level = 0;
    m_HP = 0;
    m_maxHP = 0;
    pItem = NULL;
}

// Creature deconstructor
Creature::~Creature()
{

}

void Creature::attemptMove()
{

}

void Creature::setLevel(int level)
{
	m_level = level;
} 

int Creature::getLevel()
{
	return m_level;
}

void Creature::setHP(int HP)
{
	m_HP = HP;
}

int Creature::getHP()
{
	return m_HP;
}

void Creature::setMaxHP(int maxHP)
{
	m_maxHP = maxHP;
    setHP(maxHP);
}

int Creature::getMaxHP()
{
	return m_maxHP;
}

void Creature::setInventory(Item * pItem)
{
    bool bWeapon = false;
    bool bArmor = false;
    if( (dynamic_cast<Weapon*>(pItem)) != NULL )
    {
        bWeapon = true;
        setWeapon(dynamic_cast<Weapon*>(pItem));
    }
    else if( (dynamic_cast<Armor*>(pItem) != NULL) )
    {
        bArmor = true;
        setArmorType(dynamic_cast<Armor*>(pItem));
    }
    for( size_t i = 0 ; i < inventory.size() ; i++ )
    {
        if( bWeapon == true && dynamic_cast<Weapon*>(inventory[i]) != NULL )
        {
            pItemDrop = inventory[i];
            inventory.erase(inventory.begin() + i);
            break;
        }
        else if( bArmor == true && dynamic_cast<Armor*>(inventory[i]) != NULL )
        {
            pItemDrop = inventory[i];
            inventory.erase(inventory.begin() + i);
            break;
        }
        else
        {
            pItemDrop = NULL;
        }
    }
    inventory.push_back(pItem);
}

void Creature::getInventory()
{
    string ans;
    
    for( size_t i = 0 ; i < inventory.size() ; i++ )
    {
        if( dynamic_cast<Consumable*>(inventory[i]) != NULL )
        {
            cout << i << " - " << inventory[i]->Entity::getName() << endl;
        }
    }
    cout << "q - quit" << endl;
	cout << "Which item do you wanna use? ";
    cin >> ans;
    cout << endl;

    if(ans == "q" || atoi( ans.c_str() ) > inventory.size() || atoi( ans.c_str() ) < 0 || dynamic_cast<Armor*>(inventory[atoi( ans.c_str() )]) != NULL || dynamic_cast<Weapon*>(inventory[atoi( ans.c_str() )]) != NULL) 
    {
        pItem = NULL;
    }
    else if(atoi( ans.c_str() ) < inventory.size() && atoi( ans.c_str() ) >= 0 )
    {
        pItem = inventory[atoi( ans.c_str() )];
        inventory.erase(inventory.begin() + atoi( ans.c_str() ));
    }

    if( dynamic_cast<Weapon*>(pItem) == NULL && dynamic_cast<Armor*>(pItem))
    {
        dynamic_cast<Consumable*>(pItem)->use();
        if( getHP() < 51 )
        {
            setHP(getHP() + dynamic_cast<Consumable*>(pItem)->getHealth());
            if( getHP() > 100 )
            {
                setHP(100);
            }
        }
    }
    /*else if( dynamic_cast<Consumable*>(pItem) == NULL && dynamic_cast<Armor*>(pItem) )
    {
        setWeapon(dynamic_cast<Weapon*>(pItem));
    }
    else if( dynamic_cast<Consumable*>(pItem) == NULL && dynamic_cast<Weapon*>(pItem) == NULL)
    {
        setArmor(dynamic_cast<Armor*>(pItem));
    }*/
} 

void Creature::setDropItem()
{
    string ans;
    for( size_t i = 0 ; i < inventory.size() ; i++ )
    {
        cout << i << " - " << inventory[i]->Entity::getName() << endl;
    }
    cout << "q - quit" << endl;
    cout << "Which Item Do you want to drop? ";
    cin >> ans;
    cout << endl;
    
    if(ans == "q" || atoi( ans.c_str() ) > inventory.size() || atoi( ans.c_str() ) < 0 ) 
    {
        pItemDrop = NULL;
    }
    else if( atoi( ans.c_str() ) < inventory.size() && atoi( ans.c_str() ) >= 0 )
    {
        pItemDrop = inventory[atoi( ans.c_str() )];
        inventory.erase(inventory.begin() + atoi( ans.c_str() ));
    }
}

Item * Creature::getDropItem()
{
    return pItemDrop;
}

void Creature::setWeapon( Weapon * pWeapon )
{
    m_pWeapon = pWeapon;
}

Weapon * Creature::getWeapon()
{
    return m_pWeapon;
}

void Creature::setArmorType( Armor * pArmor )
{
    m_pArmor = pArmor;
}

Armor * Creature::getArmorType()
{
    return m_pArmor;
}

void Creature::dumpObject()
{
	cout << "Creature: " << endl;
	dumpObjectData();
}

void Creature::dumpObjectData()
{
	cout << " - Level = " << m_level << endl;
	cout << " - HP = " << m_HP << endl;
	cout << " - Max HP = " << m_maxHP << endl;
	for (size_t i=0 ; i < inventory.size() ; i++)
	{
		cout << " - Inventory = " << inventory[i] << endl;
	}
	Entity::dumpObjectData(); 
}

void Creature::writeFragment(ostream & output)
{
	output << "\t <Creature>" << endl;
	writeDataAsFragment(output);
	output << "\t </Creature>" << endl;
}

void Creature::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);
	output << "\t \t<level>" << m_level << "</level>" << endl;
	output << "\t \t <HP>" << m_HP << "</HP>" << endl;
	output << "\t \t <maxHP>" << m_maxHP << "</maxHP>" << endl;
	for (size_t i=0 ; i < inventory.size() ; i++)
	{
		output << "/t/t<inventory>" << inventory[i] << "</inventory>" << endl;
	}
}

void Creature::setElementData(string elementName, string Value)
{
	if(elementName == "level")
	{
		int number = atoi(Value.c_str()); 
		setLevel(number);
	}
	else if(elementName == "HP")
	{
		int number = atoi(Value.c_str()); 
		setHP(number);
	}
	else if(elementName == "maxHP")
	{
		int number = atoi(Value.c_str()); 
		setMaxHP(number);
	}
	else
	{
		Entity::setElementData(elementName, Value);
	}
}

