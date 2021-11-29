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

	boxes[0]->product->name = "";
	boxes[0]->product->price_per_kg = 1;
	boxes[0]->product->package_size = 1;
	boxes[0]->product->storage_life = 1;
	boxes[0]->price = boxes[0]->product->package_size * boxes[0]->product->price_per_kg;

	boxes[1]->product->name = "";
	boxes[1]->product->price_per_kg = 1;
	boxes[1]->product->package_size = 1;
	boxes[1]->product->storage_life = 1;
	boxes[1]->price = boxes[1]->product->package_size * boxes[1]->product->price_per_kg;

	boxes[2]->product->name = "";
	boxes[2]->product->price_per_kg = 1;
	boxes[2]->product->package_size = 1;
	boxes[2]->product->storage_life = 1;
	boxes[2]->price = boxes[2]->product->package_size * boxes[2]->product->price_per_kg;

	boxes[3]->product->name = "";
	boxes[3]->product->price_per_kg = 1;
	boxes[3]->product->package_size = 1;
	boxes[3]->product->storage_life = 1;
	boxes[3]->price = boxes[3]->product->package_size * boxes[3]->product->price_per_kg;

	boxes[4]->product->name = "";
	boxes[4]->product->price_per_kg = 1;
	boxes[4]->product->package_size = 1;
	boxes[4]->product->storage_life = 1;
	boxes[4]->price = boxes[4]->product->package_size * boxes[4]->product->price_per_kg;

	boxes[5]->product->name = "";
	boxes[5]->product->price_per_kg = 1;
	boxes[5]->product->package_size = 1;
	boxes[5]->product->storage_life = 1;
	boxes[5]->price = boxes[5]->product->package_size * boxes[5]->product->price_per_kg;

	boxes[6]->product->name = "";
	boxes[6]->product->price_per_kg = 1;
	boxes[6]->product->package_size = 1;
	boxes[6]->product->storage_life = 1;
	boxes[6]->price = boxes[6]->product->package_size * boxes[6]->product->price_per_kg;
}

int64_t Rules::getNumberOfBuilding(is::Builds type) {
	return numbers_of_buildings[type];
}

void Rules::setNumberOfBuilding(is::Builds type, int64_t number) {
	numbers_of_buildings[type] = number;
}
