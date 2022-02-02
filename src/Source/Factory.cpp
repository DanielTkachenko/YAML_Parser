#include "Factory.h"
#include "Parser.h"
#include "Visitor.h"
#include "StreamSource.h"
#include "StreamSink.h"
#include "StringSource.h"
#include "StringSink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"

IParser* Factory::makeParser(std::string str, ISource* _source)
{
	if (str == "logging")
		return new DecoratorParser(new Parser(_source));
	return new Parser(_source);
}

ISink* Factory::makeSink(std::string str)
{
	if (str == "loggingfile")
		return new DecoratorSink(new StreamSink());
	else if (str == "loggingstring")
		return new DecoratorSink(new StringSink());
	else if (str == "file")
		return new StreamSink();
	else if (str == "string")
		return new StringSink();
	//!!!
	return new StreamSink();
}

ISource* Factory::makeSource(std::string str)
{
	if (str == "loggingfile")
		return new DecoratorSource(new StreamSource());
	else if (str == "loggingstring")
		return new DecoratorSource(new StringSource());
	else if (str == "file")
		return new StreamSource();
	else if (str == "string")
		return new StringSource();
	//!!!
	return new StreamSource();
}

IVisitor* Factory::makeVisitor(std::string str, ISink* _sink)
{
	if (str == "logging")
		return new DecoratorVisitor(new Visitor(_sink));
	return new Visitor(_sink);
}
