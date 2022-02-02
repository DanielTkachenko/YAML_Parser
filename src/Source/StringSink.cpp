#include "StringSink.h"

void StringSink::recWrite(YAML_Obj* obj)
{
    string spaces = " ";
    for (int i = 0; i < obj->nestLvl; i++)
    {
        spaces = spaces + "  ";
    }
    cout << spaces + obj->key << ": ";

    if (!obj->nestedObjs.empty())
    {
        cout << std::endl;
        for (auto nestElemet : obj->nestedObjs)
        {
            recWrite(nestElemet);
        }
    }
    else
    {
        cout << obj->value << endl;
    }
}

StringSink::StringSink()
{
}

StringSink::~StringSink()
{
}

void StringSink::write(std::vector<YAML_Obj*>& yamlVec)
{
    for (auto elem : yamlVec)
    {
        recWrite(elem);
    }
}
