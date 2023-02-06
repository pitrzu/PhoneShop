#pragma once
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <vector>
#include <sstream>
#include "Phone.h"
#include "Phone.h"

class FileManager
{
private:
	std::fstream file;
	FileManager(std::string fileName) {
		file.open(fileName);
	}
public:
	FileManager() = delete;
	
	static std::vector<shop::Phone> loadPhonesFromFile(std::string fileName);
	static void savePhonesToFile(std::string fileName, std::vector<shop::Phone> phones);

	~FileManager() {
		file.close();
	}
};

#endif