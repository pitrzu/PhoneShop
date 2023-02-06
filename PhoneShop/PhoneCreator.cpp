#include "PhoneCreator.h"
#include "StdInLoader.h"

namespace shop {
	Phone PhoneCreator::CreatePhone() {
		std::string brandName = StdInLoader::loadString("Brand name"),
			modelName = StdInLoader::loadString("Model name"),
			formFactor = StdInLoader::loadString("Form factor");
		int yearOfIssue = StdInLoader::loadInt("Year of issue");
		double screenSize = StdInLoader::loadDouble("Screen size"),
			price = StdInLoader::loadDouble("Price");

		return Phone(brandName, modelName, formFactor, yearOfIssue, screenSize, price);
	}
}