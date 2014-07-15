//parseElement.h

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA1

#include <iostream>
#include <vector>
#include "XMLSerializable.h"

#ifndef _parseElement_Included_
#define _parseElement_Included_

bool parseElement(std::istream & input, XMLSerializable * pXMLSerializable, std::vector<XMLSerializable*> &vObjects);

#endif