#ifndef SHOP_PHONE_H
#define SHOP_PHONE_H

#include <string>

namespace shop {
	class Phone {
	public:
		std::string brandName;
		std::string modelName;
		std::string formFactor;
		int yearOfIssue;
		double screenSize;
		double price;
		Phone(std::string brandName,
			std::string modelName,
			std::string formFactor,
			int yearOfIssue,
			double screenSize,
			double price) : brandName(brandName),
			modelName(modelName),
			formFactor(formFactor),
			yearOfIssue(yearOfIssue),
			screenSize(screenSize),
			price(price) {}


		std::string toString() {
			return "Brand name: " + brandName + "\n" +
				"Model name: " + modelName + "\n" +
				"Form factor: " + formFactor + "\n" +
				"Year of issue: " + std::to_string(yearOfIssue) + "\n" +
				"Screen size: " + std::to_string(screenSize) + "\n" +
				"Price: " + std::to_string(price) + "\n\n";
		};
	};
}

#endif // !SHOP_PHONE_H