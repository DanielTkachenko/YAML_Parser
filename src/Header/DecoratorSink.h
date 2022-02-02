#pragma once
#include "ISink.h"
#include "YAML_Obj.h"
#include <iostream>
#include <spdlog/spdlog.h>

class DecoratorSink : public ISink
{
protected:
	ISink* snk;
public:
	DecoratorSink(ISink* snk) : snk(snk) {}

	inline virtual void write(std::vector<YAML_Obj*>& yamlVec) override
	{
		spdlog::info("Sink start");
		snk->write(yamlVec);
		spdlog::info("Sink stop");
	}
};