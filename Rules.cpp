#include "Rules.h"

int64_t Rules::getCountType() {
	return num_of_types_;
}

int64_t Rules::getBound() {
	return max_bound_;
}

Rules::Rules(std::vector<is::WholesaleBox*>& boxes) {
	num_of_products_ = boxes.size();
	num_of_types_ = 3;
	max_bound_ = 1;
	numbers_of_buildings.resize(4); // задаем, сколько типов зданий
	boxes.resize(17);
	boxes[0] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);
	boxes[1] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);
	boxes[2] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);
	boxes[3] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);
	boxes[4] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);
	boxes[5] = new is::WholesaleBox(new is::Product("", 1, 1, 1), 1 * 1);

	boxes.resize(num_of_products_);



}

int64_t Rules::getNumberOfBuilding(is::Builds type) {
	return numbers_of_buildings[type];
}

void Rules::setNumberOfBuilding(is::Builds type, int64_t number) {
	numbers_of_buildings[type] = number;
}
