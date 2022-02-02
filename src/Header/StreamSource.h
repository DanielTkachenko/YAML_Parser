#pragma once

#include "YAML_Obj.h"
#include "ISource.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StreamSource : public ISource
{
public:

    StreamSource();
    ~StreamSource();

    void read(std::string& generalString) override;

};

inline StreamSource::StreamSource()
{
}

inline StreamSource::~StreamSource()
{
}

inline void StreamSource::read(std::string& generalString)
{
    std::ifstream file;
    //тут ввести необходимый адрес файла
    file.open("D:\\tmp\\mylab.yaml");
    if (file.is_open())
    {
        while (!file.eof())
        {
            string curLine;
            std::getline(file, curLine);
            generalString += curLine + '\n';
        }
        
        file.close();
    }
}
