#include "Rules.h"

Rules::Rules(std::vector<is::WholesaleBox*>& boxes) {
	num_of_products_ = boxes.size();
	numbers_of_buildings.resize(4); // задаем, сколько типов зданий
	boxes.resize(17);
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid_price(83, 93);
	std::uniform_int_distribution<> uid_size(12, 17);
	std::uniform_int_distribution<> uid_life(10 , 14);
	boxes[0] = new is::WholesaleBox(new is::Product("Bananas", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[0]->price = boxes[0]->product->package_size * boxes[0]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 36,56 };
	uid_size = std::uniform_int_distribution<>{ 10,15 };
	uid_life = std::uniform_int_distribution<>{ 10 , 14 };
	boxes[1] = new is::WholesaleBox(new is::Product("Apples", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[1]->price = boxes[1]->product->package_size * boxes[1]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 325,375 };
	uid_size = std::uniform_int_distribution<>{ 5,10 };
	uid_life = std::uniform_int_distribution<>{ 10 , 14 };
	boxes[2] = new is::WholesaleBox(new is::Product("Tomatoes", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[2]->price = boxes[2]->product->package_size * boxes[2]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 60,70 };
	uid_size = std::uniform_int_distribution<>{ 1,3 };
	uid_life = std::uniform_int_distribution<>{ 3 , 4 };
	boxes[3] = new is::WholesaleBox(new is::Product("Bread", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[3]->price = boxes[3]->product->package_size * boxes[3]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 240,260 };
	uid_size = std::uniform_int_distribution<>{ 7,10 };
	uid_life = std::uniform_int_distribution<>{ 8 , 10 };
	boxes[4] = new is::WholesaleBox(new is::Product("Cucumbers", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[4]->price = boxes[4]->product->package_size * boxes[4]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 16,25 };
	uid_size = std::uniform_int_distribution<>{ 10,20 };
	uid_life = std::uniform_int_distribution<>{ 10 , 14 };
	boxes[5] = new is::WholesaleBox(new is::Product("Potatoes", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[5]->price = boxes[5]->product->package_size * boxes[5]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 8,12 };
	uid_size = std::uniform_int_distribution<>{ 3,5 };
	uid_life = std::uniform_int_distribution<>{ 5 , 6 };
	boxes[6] = new is::WholesaleBox(new is::Product("Eggs", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[6]->price = boxes[6]->product->package_size * boxes[6]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 95,110 };
	uid_size = std::uniform_int_distribution<>{ 10 , 20 };
	uid_life = std::uniform_int_distribution<>{ 30 , 40 };
	boxes[7] = new is::WholesaleBox(new is::Product("Oil", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[7]->price = boxes[7]->product->package_size * boxes[7]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 60,85 };
	uid_size = std::uniform_int_distribution<>{ 12,17 };
	uid_life = std::uniform_int_distribution<>{ 8 , 9 };
	boxes[8] = new is::WholesaleBox(new is::Product("Orange", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[8]->price = boxes[8]->product->package_size * boxes[8]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 250,350 };
	uid_size = std::uniform_int_distribution<>{ 45,50 };
	uid_life = std::uniform_int_distribution<>{ 4 , 5 };
	boxes[9] = new is::WholesaleBox(new is::Product("Pork", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[9]->price = boxes[9]->product->package_size * boxes[9]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 36,46 };
	uid_size = std::uniform_int_distribution<>{ 20 , 30 };
	uid_life = std::uniform_int_distribution<>{ 50 , 60 };
	boxes[10] = new is::WholesaleBox(new is::Product("Sugar", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[10]->price = boxes[10]->product->package_size * boxes[10]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 1150,2000 };
	uid_size = std::uniform_int_distribution<>{ 1 , 2 };
	uid_life = std::uniform_int_distribution<>{ 3 , 4 };
	boxes[11] = new is::WholesaleBox(new is::Product("Salmon", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[11]->price = boxes[11]->product->package_size * boxes[11]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 45000,50000 };
	uid_size = std::uniform_int_distribution<>{ 1 , 2 };
	uid_life = std::uniform_int_distribution<>{ 4 , 6 };
	boxes[12] = new is::WholesaleBox(new is::Product("Caviar", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[12]->price = boxes[12]->product->package_size * boxes[12]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 65,85 };
	uid_size = std::uniform_int_distribution<>{ 8 , 16 };
	uid_life = std::uniform_int_distribution<>{ 10 , 11 };
	boxes[13] = new is::WholesaleBox(new is::Product("Tangerines", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[13]->price = boxes[13]->product->package_size * boxes[13]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 250,300 };
	uid_size = std::uniform_int_distribution<>{ 8 , 12 };
	uid_life = std::uniform_int_distribution<>{ 9 , 10 };
	boxes[14] = new is::WholesaleBox(new is::Product("Kiwi", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[14]->price = boxes[14]->product->package_size * boxes[14]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 20,30 };
	uid_size = std::uniform_int_distribution<>{ 10 , 20 };
	uid_life = std::uniform_int_distribution<>{ 5 , 6 };
	boxes[15] = new is::WholesaleBox(new is::Product("Milk", uid_price(gen), uid_size(gen), uid_life(gen)), 1 * 1);
	boxes[15]->price = boxes[15]->product->package_size * boxes[15]->product->price_per_kg;
	uid_price = std::uniform_int_distribution<>{ 550,625 };
	uid_size = std::uniform_int_distribution<>{ 8 , 10 };
	uid_life = std::uniform_int_distribution<>{ 8 , 12 };
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
