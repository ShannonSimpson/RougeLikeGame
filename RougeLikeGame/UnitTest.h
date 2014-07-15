//Shannon Simpson
//Shannon.Simpson1020@gmail.com
//UnitTest.cpp

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#ifndef _UnitTest_included_
#define _UnitTest_included_

class UnitTest
{
public:
	UnitTest();
	~UnitTest();
	virtual void markPosition(std::vector<std::string> & vTempString, int x, int y);
	virtual bool testLevel(std::vector<std::string> & vTempString);

private:
	std::vector<std::string> vTempString;

};
#endif