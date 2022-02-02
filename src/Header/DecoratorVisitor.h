#pragma once
#include "IVisitor.h"
#include <iostream>
#include <spdlog/spdlog.h>

class DecoratorVisitor : public IVisitor
{
protected:
	IVisitor* _visitor;
public:
	DecoratorVisitor(IVisitor* visitor) : _visitor(visitor) {}

	inline virtual pair<string, int> onParseKey(string& key, int nestLvl) override
	{
		spdlog::info("onParseKey: " + key);
		return _visitor->onParseKey(key, nestLvl);
	}

	inline virtual pair<string, int> onParseStr(string& string) override
	{
		spdlog::info("onParseStr: " + string);
		return _visitor->onParseStr(string);
	}

	inline virtual pair<string, int> onParseNumber(string& number) override
	{
		spdlog::info("onParseNumber: " + number);
		return _visitor->onParseNumber(number);
	}

	inline virtual pair<string, int> onParseBool(string& boolean) override
	{
		spdlog::info("onParseBool: " + boolean);
		return _visitor->onParseBool(boolean);
	}

	inline virtual pair<string, int> onParseList(string& list) override
	{
		spdlog::info("onParseList: " + list);
		return _visitor->onParseList(list);
	}

	inline virtual void onParseNest() override
	{
		spdlog::info("!");
		return _visitor->onParseNest();
	}

	inline virtual void onFinished() override
	{
		spdlog::info("onFinished()");
		return _visitor->onFinished();
	}
};