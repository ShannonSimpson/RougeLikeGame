//CreatureFactory.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA3

#include "CreatureFactory.h"
#include "XMLSerializable.h"
#include "parseXML.h"
#include <fstream>
#include <ctime>
#include <vector>


using namespace std;


CreatureFactory & CreatureFactory::instance()
{
    static CreatureFactory factory;

    return factory;  
}

CreatureFactory::CreatureFactory()
{
    ifstream input;
    input.open("critters.xml");

    vector<XMLSerializable*> vCreatures;
    parseXML(input, vCreatures);

    for( auto it = vCreatures.begin(); it != vCreatures.end(); it++ )
    {
        Creature * pCreature = dynamic_cast<Creature*>(*it);
        if( pCreature != NULL )
        {
            m_vCreatures.push_back(pCreature);
        }
    }
}

CreatureFactory::~CreatureFactory()
{
}

Creature * CreatureFactory::generateCreature(int iMaxLevel)
{
    vector<Creature*> vProperCreatures;

    for( auto it = m_vCreatures.begin();
            it != m_vCreatures.end(); it++)
    {
        if( (*it)->getLevel() <= iMaxLevel )
        {
            vProperCreatures.push_back(*it);
        }
    }

    if( vProperCreatures.size() == 0 )
    {
        return NULL;
    }

    int iIndex = mt() % vProperCreatures.size();

    Creature * pCreature = vProperCreatures[iIndex];

    Creature * pReturnValue = new Creature(*pCreature);

    return pReturnValue;
}
