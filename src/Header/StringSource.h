#pragma once
#include "ISource.h"

#include <iostream>
#include <string>
using namespace std;

class StringSource : public ISource
{
public:
	StringSource();
	~StringSource();
	// Унаследовано через Source
	void read(string& inputString) override;
};

inline StringSource::StringSource()
{
}
inline StringSource::~StringSource()
{
}

inline void StringSource::read(string& inputString)
{
	getline(std::cin, inputString);
}