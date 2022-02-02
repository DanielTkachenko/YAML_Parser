#pragma once
#include "IParser.h"
#include <iostream>
#include <spdlog/spdlog.h>

class DecoratorParser : public IParser
{
protected:
	IParser* _parser;
public:
	DecoratorParser(IParser* parser) : _parser(parser) {}

	inline virtual void parse(IVisitor* visitor) override
	{
		spdlog::info("Parser start");
		_parser->parse(visitor);
		spdlog::info("Parser stop");
	}
};