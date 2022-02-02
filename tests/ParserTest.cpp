#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Parser.h"
#include "Visitor.h"
#include "IParser.h"
#include "IVisitor.h"
#include "ISource.h"
#include "ISink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"
#include "Factory.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class MockVisitor : public Visitor
{
public:
    MockVisitor(ISink* sink);
    ~MockVisitor();

    MOCK_METHOD2(onParseKey, std::pair<std::string, int>(std::string& key, int nestLvl));
    MOCK_METHOD1(onParseStr, std::pair<std::string, int>(std::string& string));
    MOCK_METHOD1(onParseNumber, std::pair<std::string, int>(std::string& number));
    MOCK_METHOD1(onParseBool, std::pair<std::string, int>(std::string& boolean));
    MOCK_METHOD1(onParseList, std::pair<std::string, int>(std::string& list));
    MOCK_METHOD0(onParseNest, void());
    MOCK_METHOD0(onFinished, void());
};

MockVisitor::MockVisitor(ISink* Sink) : Visitor(Sink)
{

}

MockVisitor::~MockVisitor()
{

}

TEST(ParserTest, trueTest) {

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    sourceType = sourceType + "file";

    ISource* currentSource = Factory::makeSource(sourceType);

    ISink* sink = Factory::makeSink(sinkType);

    MockVisitor mockVisitor(sink);

    IParser* prs = Factory::makeParser(parserType, currentSource);

    
    EXPECT_CALL(mockVisitor, onParseKey).Times(11);
    EXPECT_CALL(mockVisitor, onParseStr).Times(5);
    EXPECT_CALL(mockVisitor, onParseNumber).Times(3);
    EXPECT_CALL(mockVisitor, onParseBool).Times(2);

    prs->parse(&mockVisitor);
}