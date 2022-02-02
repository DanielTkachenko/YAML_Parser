#pragma once

#include <iostream>
#include <string>
using namespace std;

class ISource
{
public:
	virtual void read(string & inputString) = 0;
};