cmake_minimum_required(VERSION 3.16.0)

project(parser-lib VERSION 1.0.0 LANGUAGES CXX)

enable_testing()

add_library(${PROJECT_NAME} 
Header/Factory.h Source/Factory.cpp 
Header/IParser.h 
Header/ISink.h 
Header/ISource.h 
Header/IVisitor.h 
Header/Parser.h Source/Parser.cpp 
Header/StreamSink.h Source/StreamSink.cpp 
Header/StreamSource.h 
Header/StringSink.h Source/StringSink.cpp 
Header/StringSource.h 
Header/Visitor.h Source/Visitor.cpp 
Header/YAML_Obj.h 
Header/DecoratorParser.h 
Header/DecoratorSink.h 
Header/DecoratorSource.h 
Header/DecoratorVisitor.h)

target_include_directories(${PROJECT_NAME} PUBLIC Header)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})