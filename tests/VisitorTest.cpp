#include <gtest/gtest.h>
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

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

TEST(VisitorTest, trueTest) {

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    sourceType = sourceType + "file";

    ISource* currentSource = Factory::makeSource(sourceType);

    ISink* sink = Factory::makeSink(sinkType);

    Visitor visitor(sink);

    std::string key = "key";
    std::string value = "value";

    visitor.onParseKey(key, 0);

    key = key + "1";
    visitor.onParseKey(key, 1);
    visitor.onParseStr(value);
    visitor.onParseKey(key, 1);
    key = "key2";
    visitor.onParseKey(key, 2);
    visitor.onParseStr(value);
    visitor.onParseKey(key, 2);
    visitor.onParseStr(value);
    key = "key";

    visitor.onParseKey(key, 0);
    key = key + "1";
    visitor.onParseKey(key, 1);
    visitor.onParseStr(value);


    EXPECT_EQ(visitor.yamlVec.size(), 2);
    EXPECT_EQ(visitor.yamlVec[0]->nestedObjs.size(), 2);
    EXPECT_EQ(visitor.yamlVec[0]->nestedObjs[1]->nestedObjs.size(), 2);
    EXPECT_EQ(visitor.yamlVec[1]->nestedObjs.size(), 1);
}