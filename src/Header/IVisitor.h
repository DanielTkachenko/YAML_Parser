#pragma once

#include <utility>
#include <string>
using namespace std;

class IVisitor
{
public:
    virtual pair<string, int> onParseKey(string& key, int nestLvl) = 0;
    virtual pair<string, int> onParseStr(string& string) = 0;
    virtual pair<string, int> onParseNumber(string& number) = 0;
    virtual pair<string, int> onParseBool(string& boolean) = 0;
    virtual pair<string, int> onParseList(string& list) = 0;
    virtual void onParseNest() = 0;

    virtual void onFinished() = 0;

    virtual ~IVisitor() {};
};

