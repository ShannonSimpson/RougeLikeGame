//Tile.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3


#include "Tile.h"
#include <ncurses.h>

using namespace std;

Tile::Tile(char c, bool stopWalking)
{
    m_stopWalking = stopWalking;
    m_c = c;

    bCreature = false;
    bItem = false;
}

Tile::~Tile()
{}


bool Tile::returnBool()
{
    return m_stopWalking;
}

bool Tile::returnCreatureBool()
{
    return bCreature;
}

bool Tile::returnItemBool()
{
    return bItem;
}

void Tile::setItems( Item * pItem )
{
    if( pItem->getName() != "" )
    {
        Items.push_back(pItem);
        bItem = true;
    }
}

void Tile::pickUpItem()
{
    string ans;
    for( size_t i = 0 ; i < Items.size() ; i++ )
    {
        //cout << i << " - " << Items[i]->getName() << endl;
		mvprintw(25,0,"Which one? type in the number: first, second, third...");
		mvprintw(26,0, "# - %s",Items[i]->getName().c_str());
    }
    //cout << "q - quit" << endl;
	mvprintw(27,0, "q - quit");
    //cout << "What do you want to pick up? " ;
	mvprintw(25,0,"What do you want to pick up? ");
    cin >> ans;
	ans = getch();
    //cout << endl;
    Item * tempItem;
    if(ans == "q" || atoi( ans.c_str() ) > Items.size() || atoi( ans.c_str() ) < 0 ) 
    {
        //cout << "That isn't an option" << endl;
		mvprintw(26,0,"That isn't an option");
    }
    else if( atoi( ans.c_str() ) < Items.size() && atoi( ans.c_str() ) >= 0 )
    {
        m_onlyCreature->Creature::setInventory(Items[atoi( ans.c_str() )]);
        Items.erase(Items.begin() + atoi( ans.c_str() ));
    }
    for(size_t i = 0 ; i < Items.size() ; i++ )
    {
        //cout << Items[i]->Entity::getName() << endl;
		mvprintw(27,0,"%s",Items[i]->Entity::getName().c_str());
    }
    if( Items.size() == 0 )
    {
        bItem = false;
    }
}

char Tile::tileDisplayChar()
{
    if( bCreature == true )
    {
        return m_onlyCreature->getDisplayChar();
    }
    else if( bItem == true )
    {
        return Items[Items.size()-1]->getDisplayChar(); 
    }
    else
    {
        return m_c;
    }
}

void Tile::setCreature(Creature * onlyCreature)
{
    //m_stopWalking = false;
    bCreature = true;   
    m_onlyCreature = onlyCreature;
}

void Tile::removeCreature()
{
    //m_stopWalking = true;
    bCreature = false;
    m_onlyCreature = NULL;
}

Creature * Tile::getCreature()
{
    return m_onlyCreature;
}
