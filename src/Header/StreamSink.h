#pragma once
#include "ISink.h"
#include "YAML_Obj.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class StreamSink : public ISink
{
private:
	void recWrite(YAML_Obj* obj, std::string& fileStr);
public:
	StreamSink();
	~StreamSink();

	void write(std::vector<YAML_Obj*>& yamlVec) override;

};

