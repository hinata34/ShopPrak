#include "Rules.h"

int64_t Rules::getCountType() {
	return num_of_types_;
}

int64_t Rules::getBound() {
	return max_bound_;
}

void Rules::CreateRules(std::vector<WholesaleBox*>& boxes) {
	num_of_products_ = boxes.size();
	num_of_types_ = 3;
	max_bound_ = 1;
	numbers_of_buildings.resize(4); // задаем, сколько зданий
	for (size_t i = 0; i < boxes.size(); ++i) {
		switch (i) {
		case is::Products::Product1:
			boxes[i] = new WholesaleBox(new Product("", 1, 1, 1), 1);
			break;
		case is::Products::Product2:
			boxes[i] = new WholesaleBox(new Product("", 1, 1, 1), 1);
			break;
		case is::Products::Product3:
			boxes[i] = new WholesaleBox(new Product("", 1, 1, 1), 1);
			break;
		case is::Products::Product4:
			boxes[i] = new WholesaleBox(new Product("", 1, 1, 1), 1);
			break;
		case is::Products::Product5:
			boxes[i] = new WholesaleBox(new Product("", 1, 1, 1), 1);
			break;
		default:
			break;
		}
	}

}

void Rules::setNumberOfBuilding(is::Builds type, int64_t number) {
	switch (type) {
	case is::Builds::Shop:
		numbers_of_buildings[type] = number;
		break;
	case is::Builds::Storage:
		numbers_of_buildings[type] = number;
		break;
	case is::Builds::SuperStorage:
		numbers_of_buildings[type] = number;
		break;
	case is::Builds::Trash:
		numbers_of_buildings[type] = number;
		break;
	default:
		break;
	}
}

int64_t Rules::getNumberOfBuilding(is::Builds type) {
	switch (type) {
	case is::Builds::Shop:
		return numbers_of_buildings[type];
		break;
	case is::Builds::Storage:
		return numbers_of_buildings[type];
		break;
	case is::Builds::SuperStorage:
		return numbers_of_buildings[type];
		break;
	case is::Builds::Trash:
		return numbers_of_buildings[type];
		break;
	default:
		return -1;
		break;
	}
}
