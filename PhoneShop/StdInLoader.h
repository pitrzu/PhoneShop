#pragma once

#ifndef STD_IN_LOADER_H
#define STD_IN_LOADER_H

#include <string>
#include <iostream>
class StdInLoader
{
public:
	static std::string loadString(std::string fieldName);
	static double loadDouble(std::string fieldName);
	static int loadInt(std::string fieldName);
};

#endif