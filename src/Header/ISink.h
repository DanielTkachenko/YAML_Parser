#pragma once

#include "YAML_Obj.h"

#include <iostream>
#include <string>
#include <vector>

class ISink
{
public:

    virtual void write(std::vector<YAML_Obj*>& yamlVec) = 0;
};