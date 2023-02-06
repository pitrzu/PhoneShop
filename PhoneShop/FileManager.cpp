#include "FileManager.h"



std::vector<shop::Phone> FileManager::loadPhonesFromFile(std::string fileName) {
	std::vector<shop::Phone> out;
	FileManager fm(fileName);

	std::string line;
	while (!fm.file.eof()) {
		std::getline(fm.file, line, ';');
		std::stringstream ss(line);
		std::string item;
		

		std::vector<std::string> singlePhone;
		while (std::getline(ss, item, '-')) {
			singlePhone.push_back(item);
		}

		auto phone = shop::Phone(singlePhone[0], singlePhone[1], singlePhone[2], std::stoi(singlePhone[3]), std::stod(singlePhone[4]), std::stod(singlePhone[5]));
		out.push_back(phone);
	}


	return out;
}

void FileManager::savePhonesToFile(std::string fileName, std::vector<shop::Phone> phones)
{
}

