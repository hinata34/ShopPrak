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
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid_price(0, 5);
	std::uniform_int_distribution<> uid_size(0, 5);
	std::uniform_int_distribution<> uid_life(0, 5);
	boxes[0] = new is::WholesaleBox(new is::Product("Bananas", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[0]->price = boxes[0]->product->package_size * boxes[0]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[1] = new is::WholesaleBox(new is::Product("Apples", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[1]->price = boxes[1]->product->package_size * boxes[1]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[2] = new is::WholesaleBox(new is::Product("Tomatoes", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[2]->price = boxes[2]->product->package_size * boxes[2]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[3] = new is::WholesaleBox(new is::Product("Bread", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[3]->price = boxes[3]->product->package_size * boxes[3]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[4] = new is::WholesaleBox(new is::Product("Cucumbers", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[4]->price = boxes[4]->product->package_size * boxes[4]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[5] = new is::WholesaleBox(new is::Product("Potatoes", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[5]->price = boxes[5]->product->package_size * boxes[5]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[6] = new is::WholesaleBox(new is::Product("Eggs", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[6]->price = boxes[6]->product->package_size * boxes[6]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[7] = new is::WholesaleBox(new is::Product("Oil", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[7]->price = boxes[7]->product->package_size * boxes[7]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[8] = new is::WholesaleBox(new is::Product("Orange", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[8]->price = boxes[8]->product->package_size * boxes[8]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[9] = new is::WholesaleBox(new is::Product("Pork", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[9]->price = boxes[9]->product->package_size * boxes[9]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[10] = new is::WholesaleBox(new is::Product("Sugar", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[10]->price = boxes[10]->product->package_size * boxes[10]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[11] = new is::WholesaleBox(new is::Product("Salmon", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[11]->price = boxes[11]->product->package_size * boxes[11]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[12] = new is::WholesaleBox(new is::Product("Caviar", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[12]->price = boxes[12]->product->package_size * boxes[12]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[13] = new is::WholesaleBox(new is::Product("Tangerines", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[13]->price = boxes[13]->product->package_size * boxes[13]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[14] = new is::WholesaleBox(new is::Product("Kiwi", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[14]->price = boxes[14]->product->package_size * boxes[14]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[15] = new is::WholesaleBox(new is::Product("Milk", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[15]->price = boxes[15]->product->package_size * boxes[15]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 154, 1500 };
	uid_size = std::uniform_int_distribution<>{ 154, 1500 };
	uid_life = std::uniform_int_distribution<>{ 154, 1500 };
	boxes[16] = new is::WholesaleBox(new is::Product("Cheese", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[16]->price = boxes[16]->product->package_size * boxes[16]->product->price_per_kg;

	boxes.resize(num_of_products_);
}

int64_t Rules::getNumberOfBuilding(is::Builds type) {
	return numbers_of_buildings[type];
}

void Rules::setNumberOfBuilding(is::Builds type, int64_t number) {
	numbers_of_buildings[type] = number;
}
