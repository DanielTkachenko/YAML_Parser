#pragma once
#include "ISink.h"
#include "YAML_Obj.h"
using namespace std;

class StringSink : public ISink
{
private:
	void recWrite(YAML_Obj* obj);
public:
	StringSink();
	~StringSink();
	// Унаследовано через ISink
	virtual void write(vector<YAML_Obj*>& yamlVec) override;
};

