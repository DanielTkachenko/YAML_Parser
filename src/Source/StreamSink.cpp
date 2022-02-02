#include "StreamSink.h"

void StreamSink::recWrite(YAML_Obj* obj, std::string& fileStr)
{
    std::string spaces = " ";
    for (int i = 0; i < obj->nestLvl; i++)
    {
        spaces = spaces + "  ";
    }
    fileStr = fileStr + spaces + obj->key + ": ";

    if (!obj->nestedObjs.empty())
    {
        fileStr = fileStr + "\n";
        for (auto nestElemet : obj->nestedObjs)
        {
            recWrite(nestElemet, fileStr);
        }
    }
    else
    {
        fileStr = fileStr + obj->value + "\n";
    }
}

StreamSink::StreamSink()
{
}

StreamSink::~StreamSink()
{
}

void StreamSink::write(std::vector<YAML_Obj*>& yamlVec)
{
    std::string fileStr = "--- \n";

    for (auto elem : yamlVec)
    {
        recWrite(elem, fileStr);
    }

    std::ofstream outFile("D:\\tmp\\mylab_out.yaml");
    if (outFile.is_open())
    {
        outFile << fileStr;
    }
}
