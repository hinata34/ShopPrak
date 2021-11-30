#include "Shop.h"

Shop::Shop() {
}

void Shop::checkOrder(std::vector<Building*> buildings) {
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
				this->createApplication(i);
			}
		}
	}
}
