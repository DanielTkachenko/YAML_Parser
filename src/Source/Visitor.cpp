#include "Visitor.h"

Visitor::Visitor(ISink* sink) /* : _sink(sink)*/
{
    baseYamlObj = new YAML_Obj;
    _sink = sink;
}

Visitor::~Visitor()
{
}

pair<string, int> Visitor::onParseKey(string& key, int nestLvl)
{
    if (nestLvl == 0)
    {
        YAML_Obj* currentYamlObj = new YAML_Obj;
        baseYamlObj = currentYamlObj;
        basedYamlObjs.insert(basedYamlObjs.begin(), baseYamlObj);
        yamlVec.push_back(baseYamlObj);
    }

    if (nestLvl > 0)
    {
        for (auto baseElem : basedYamlObjs)
        {
            if (baseElem->nestLvl == (nestLvl - 1))
            {
                YAML_Obj* currentYamlObj = new YAML_Obj;
                baseYamlObj = currentYamlObj;
                baseElem->nestedObjs.push_back(baseYamlObj);
                basedYamlObjs.insert(basedYamlObjs.begin(), baseYamlObj);
                break;
            }
        }
    }

    // std::cout << key << ":" << " ";

    baseYamlObj->key = key;
    baseYamlObj->nestLvl = nestLvl;
    return std::make_pair(key, 0);
}

pair<string, int> Visitor::onParseStr(string& string)
{
    baseYamlObj->value = string;
    return std::make_pair("outStr", 0);
}

pair<string, int> Visitor::onParseNumber(string& number)
{
    baseYamlObj->value = number;
    return std::make_pair("outNumber", 0);
}

pair<string, int> Visitor::onParseBool(string& boolean)
{
    baseYamlObj->value = boolean;
    return std::make_pair("cum", 0);
}

pair<string, int> Visitor::onParseList(string& list)
{
    baseYamlObj->value = list;
    return std::make_pair("outAllList", 0);
}

void Visitor::onParseNest()
{

}

void Visitor::onFinished()
{
    _sink->write(yamlVec);
}
