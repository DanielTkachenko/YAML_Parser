#pragma once

#include <string>
#include <vector>
using namespace std;

class YAML_Obj
{
public:
    YAML_Obj();
    ~YAML_Obj();

    vector<YAML_Obj*> nestedObjs;
    string key;
    string value;
    int nestLvl = 0;
};

inline YAML_Obj::YAML_Obj()
{
}

inline YAML_Obj::~YAML_Obj()
{
}