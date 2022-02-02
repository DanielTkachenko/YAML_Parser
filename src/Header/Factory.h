#pragma once
#include <string>
#include "IParser.h"
#include "ISink.h"
#include "ISource.h"
#include "IVisitor.h"
using namespace std;

class Factory
{
public:
	static IParser* makeParser(std::string str, ISource* _source);

	static ISink* makeSink(std::string str);

	static ISource* makeSource(std::string str);

	static IVisitor* makeVisitor(std::string str, ISink* snk);
};

