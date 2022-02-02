#pragma once

#include "IVisitor.h"

#include <string>
#include <vector>

class IParser
{
public:
	virtual void parse(IVisitor* visitor) = 0;
};