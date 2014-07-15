//parseXML.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <vector>
#include "parseElement.h"
#include "XMLSerializable.h"

#ifndef _parseXML_Included_
#define _parseXML_Included_

bool parseXML(std::istream & input, std::vector<XMLSerializable*> &vObjects);

#endif