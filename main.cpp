// ParserYaml_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "src/Header/Factory.h"
#include "src/Header/IParser.h"
#include "src/Header/IVisitor.h"
#include "src/Header/ISource.h"
#include "src/Header/ISink.h"
using namespace std;

int main()
{
    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    std::cout << "Put 0 if you don't want log process" << std::endl 
        << "Put 1 if you want log process" << std::endl;

    bool loggingOn = false;
    std::cin >> loggingOn;
    std::cin.ignore(256, '\n');

    if (loggingOn)
    {
        sourceType = "logging";
        visitorType = "logging";
        parserType = "logging";
        sinkType = "logging";
    }

    std::cout << "Put 1 if you want put string to parse" << std::endl 
        << "Put 0 if you want read file to parse" << std::endl;

    // true - string, false - file
    bool inputType = false;
    std::cin >> inputType;
    std::cin.ignore(256, '\n');

    if (inputType)
    {
        sourceType = sourceType + "string";
    }
    else
    {
        sourceType = sourceType + "file";
    }

    ISource* currentSource = Factory::makeSource(sourceType);

    std::cout << std::endl << "Put 1 if you want out parsed as string" << std::endl 
        << "Put 0 if you want out parsed string as file" << std::endl;

    // true - string, false - file
    inputType = false;
    std::cin >> inputType;

    if (inputType)
    {
        sinkType = sinkType + "string";
    }
    else
    {
        sinkType = sinkType + "file";
    }

    ISink* snk = Factory::makeSink(sinkType);
    IVisitor* firtsVisitorImp = Factory::makeVisitor(visitorType, snk);

    IParser* prs = Factory::makeParser(parserType, currentSource);
    prs->parse(firtsVisitorImp);
}

