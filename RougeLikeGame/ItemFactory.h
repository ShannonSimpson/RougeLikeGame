//ItemFactory.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA 3


#ifndef _ItemFactory_included_
#define _ItemFactory_included_

#include "Item.h"

#include <vector>
#include <random>

class ItemFactory
{
public:
	static ItemFactory & instance();
	virtual ~ItemFactory();
	Item * generateItem(int value);

private:
	ItemFactory();
	std::vector<Item*> m_vItems;
	
};

extern std::mt19937 mt;

#endif
