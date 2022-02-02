#pragma once
#include "IParser.h"
#include "IVisitor.h"
#include "ISource.h"

#include <string>
#include <vector>
using namespace std;

class Parser : public IParser
{
public:
	Parser(ISource* source);
	~Parser();
	// Унаследовано через Parser
	virtual void parse(IVisitor* visitor) override;

private:
	ISource* _source;
};

