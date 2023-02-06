#include "StdInLoader.h"


std::string StdInLoader::loadString(std::string fieldName) {
	std::string out;

	std::cout << fieldName << ": ";
	std::cin >> out;

	return out;
}

double StdInLoader::loadDouble(std::string fieldName) {
	return std::stod(loadString(fieldName), nullptr);
}

int StdInLoader::loadInt(std::string fieldName) {
	return std::stoi(loadString(fieldName), nullptr);
}