#pragma once
#ifndef SHOP_MANAGER_H
#define SHOP_MANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include "Phone.h"
#include "PhoneCreator.h"
#include "StdInLoader.h"


namespace shop {
	class ShopManager{
	private:
		std::vector<Phone> phones;
		int getMenuChoice();
		int getBoundedChoice(int low, int high);

		void printPhones(std::vector<Phone> phones);
		void printPhones();
		void showMenu();
		void addPhone();
		void removePhone();
		void generateBrandPhonesReport();
		void generateFormFactorPhonesReport();
		void generateBestSellingBrandReport();
		void generateTop3ScreenSizesReport();
		void loadFromFile();
		void saveToFile();
	public:
		void Run();
	};
}

#endif