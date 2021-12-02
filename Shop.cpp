#include "Shop.h"

Shop::Shop(int64_t days) : Building(days) {
	category = 1;
}

void Shop::checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes) {
	std::mt19937_64 gen(time(0));
	if (gen() % 2 != 0) {
		return;
	}
	for (auto i : buildings) {
		if (i->getCategory() == this->category + 1) {
			bool flag = true;
			for (auto j : expected_applications) {
				if (j->customer == i) {
					flag = false;
					break;
				}
			}
			if (flag) {
				this->createApplication(i, boxes);
				break;
			}
		}
	}
}

is::Application* Shop::generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid_product(0, 5);
	std::uniform_int_distribution<> uid_counter(0, 5);
	is::Application* application = new is::Application(this, receiver, new is::List);
	for (auto i : boxes) {
		if (uid_counter(gen) % 5 == 0) {
			application->application->push_back(new is::ElemInList(i, uid_counter(gen)));
		}
	}
	return application;
}