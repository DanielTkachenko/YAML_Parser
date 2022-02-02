#pragma once
#include "IVisitor.h"
#include "ISink.h"
#include "YAML_Obj.h"

#include <string>
#include <vector>
#include <map>
using namespace std;

class Visitor : public IVisitor
{
private:
	string inputString;
	ISink* _sink;
	YAML_Obj* baseYamlObj;
	vector<YAML_Obj*> basedYamlObjs;
	
public:
	vector<YAML_Obj*> yamlVec;

	Visitor(ISink* sink);
	~Visitor();
	// Унаследовано через Visitor
	virtual pair<string, int> onParseKey(string& key, int nestLvl) override;
	virtual pair<string, int> onParseStr(string& string) override;
	virtual pair<string, int> onParseNumber(string& number) override;
	virtual pair<string, int> onParseBool(string& boolean) override;
	virtual pair<string, int> onParseList(string& list) override;
	virtual void onParseNest() override;
	virtual void onFinished() override;
};

