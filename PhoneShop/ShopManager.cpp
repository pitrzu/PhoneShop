#include "ShopManager.h"
#include <map>



namespace shop {
	void ShopManager::Run() {
		int chosen;
		do {
			chosen = this->getMenuChoice();
			switch (chosen) {
			case 0:
				this->printPhones();
				break;
			case 1:
				this->addPhone();
				break;
			case 2:
				this->printPhones();
				this->removePhone();
				break;
			case 3:
				this->generateBrandPhonesReport();
				break;
			case 4:
				this->generateFormFactorPhonesReport();
				break;
			case 5:
				this->generateBestSellingBrandReport();
				break;
			case 6:
				this->generateTop3ScreenSizesReport();
				break;
			case 9:
				return;
			default:
				break;
			}
		} while (chosen != 9);
	}

	void ShopManager::showMenu() {
		std::cout << "Phone shop manager v1.0" << std::endl
			<< "Please choose an action: (0-8)" << std::endl
			<< "0: Print all phones" << std::endl
			<< "1: Add a phone" << std::endl
			<< "2: Remove a phone" << std::endl
			<< "3: Show all phones from a brand: " << std::endl
			<< "4: Show all phones with a form factor and|or screen size" << std::endl
			<< "5: Show best selling brand" << std::endl
			<< "6: Show top 3 best selling screen sizes" << std::endl
			<< "7: Load phones from file" << std::endl
			<< "8: Save phones to a file" << std::endl
			<< "9: Exit" << std::endl;
	}

	int ShopManager::getMenuChoice() {
		int chosen = -1;
		do {
			this->showMenu();
			std::cout << "Your choice: ";
			std::cin >> chosen;
			std::cout << std::endl;
		} while (chosen < 0 || chosen > 9);

		system("CLS");
		return chosen;
	}

	int ShopManager::getBoundedChoice(int low, int high)
	{
		int chosen = -1;
		do {
			std::cout << "Your choice: ";
			std::cin >> chosen;
			std::cout << std::endl;
		} while (chosen < low || chosen > high);

		return chosen;
	}


	void ShopManager::addPhone() {
		auto phone = PhoneCreator::CreatePhone();

		this->phones.emplace(this->phones.begin(), phone);
		std::cout << phone.toString();
	}


	void ShopManager::printPhones() {
		for (int i = 0; i < this->phones.size(); i++) {
			std::cout << "///////////////////// " << std::to_string(i) << " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" << this->phones[i].toString();
		}
	}

	void ShopManager::printPhones(std::vector<Phone> notthis_phones) {
		for (int i = 0; i < notthis_phones.size(); i++) {
			std::cout << notthis_phones[i].toString();
		}
	}

	void ShopManager::removePhone() {
		int choice = getBoundedChoice(0, this->phones.size());
		auto phone = this->phones[choice];
		phones.erase(this->phones.begin() + choice);
	}

	void ShopManager::generateBrandPhonesReport()
	{
		std::string BrandName = StdInLoader::loadString("Brand Name");
		std::vector<Phone> filtered;

		std::copy_if(this->phones.begin(), this->phones.end(), std::back_inserter(filtered), [BrandName](Phone phone) {
			return BrandName == phone.brandName;
		});

		printPhones(filtered);
	}

	void ShopManager::generateFormFactorPhonesReport()
	{
		std::string FormFactor = StdInLoader::loadString("Form factor");
		std::vector<Phone> filtered;

		std::copy_if(this->phones.begin(), this->phones.end(), std::back_inserter(filtered), [FormFactor](Phone phone) {
			return FormFactor == phone.formFactor;
		});

		printPhones(filtered);
	}

	void ShopManager::generateBestSellingBrandReport()
	{
		std::vector<std::string> brands;
		for (auto phone : this->phones) {
			brands.push_back(phone.brandName);
		}

		std::map<std::string, int> brandsWithOcc;
		for (auto brandName : brands) {
			auto found = brandsWithOcc.find(brandName);
			if (found == brandsWithOcc.end())
				brandsWithOcc.emplace(brandName, 1);
			else found->second++;
		}

		std::vector<std::pair<std::string, int>> topBrand(1);

		std::partial_sort_copy(brandsWithOcc.begin(), brandsWithOcc.end(), topBrand.begin(), topBrand.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
			return a.second > b.second;
		});

		std::cout << "Best selling brand: " << topBrand[0].first << " with: " << topBrand[0].second << " sales" << std::endl;
	}

	void ShopManager::generateTop3ScreenSizesReport()
	{
		std::vector<double> sceenSizes;
		for (auto phone : this->phones) {
			sceenSizes.push_back(phone.screenSize);
		}

		std::map<double, int> sceenSizesWithOcc;
		for (auto sceenSize : sceenSizes) {
			auto found = sceenSizesWithOcc.find(sceenSize);
			if (found == sceenSizesWithOcc.end())
				sceenSizesWithOcc.emplace(sceenSize, 1);
			else found->second++;
		}

		std::vector<std::pair<double, int>> topScreenSizes(3);

		std::partial_sort_copy(sceenSizesWithOcc.begin(), sceenSizesWithOcc.end(), topScreenSizes.begin(), topScreenSizes.end(), [](std::pair<double, int> a, std::pair<double, int> b) {
			return a.second > b.second;
		});

		std::cout << "Top 3 best selling screen sizes are: " << std::endl;

		for (auto pair : topScreenSizes) {
			std::cout << pair.first << " with: " << pair.second << " sales" << std::endl;
		}
	}
	void ShopManager::loadFromFile()
	{

	}
	void ShopManager::saveToFile()
	{

	}
}