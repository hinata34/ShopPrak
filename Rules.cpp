#include "Rules.h"

int64_t Rules::getCountType() {
	return num_of_types_;
}

int64_t Rules::getBound() {
	return max_bound_;
}

Rules::Rules(std::vector<WholesaleBox*>& boxes) {
	num_of_products_ = boxes.size();
	num_of_types_ = 3;
	max_bound_ = 1;
	numbers_of_buildings.resize(4); // задаем, сколько зданий
}

int64_t Rules::getNumberOfBuilding(is::Builds type) {
	return numbers_of_buildings[type];
}
