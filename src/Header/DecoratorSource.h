#pragma once
#include "ISource.h"
#include <iostream>
#include <spdlog/spdlog.h>

class DecoratorSource : public ISource
{
protected:
	ISource* _source;
public:
	DecoratorSource(ISource* _source) : _source(_source) {}

	inline virtual void read(string& inputString) override
	{
		spdlog::info("Source start");
		_source->read(inputString);
		spdlog::info("Source stop");
	}
};