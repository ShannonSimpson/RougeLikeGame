//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

//SpitOutOntoConsole function
//void SpitOutOntoConsole(vector<XMLSerializable *> & vObjects)

#include "SpitOutOntoConsole.h"
#include "XMLSerializable.h"

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//runs through all the dump objects to display onto console.
void SpitOutOntoConsole(vector<XMLSerializable *> & vObjects)
{
	for(size_t i = 0 ; i < vObjects.size() ; i++)
	{
		vObjects[i]->dumpObject();
	}
}