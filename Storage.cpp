#include "Storage.h"

Storage::Storage(int64_t days) : Building(days){
	category = 2;
	coef_for_price = 1.1;
}

void Storage::checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes) {

	std::map<is::WholesaleBox*, int64_t> sum_application;
	for (auto i : boxes) {
		sum_application.insert({ i, 0 });
	}
	for (auto i : applications[0]) {
		for (auto j : (*i->application)) {
			sum_application[j->product] += j->counter;
		}
	}
	std::map<is::WholesaleBox*, int64_t> sum_products;
	for (auto i : boxes) {
		sum_products.insert({ i, 0 });
	}
	for (auto i : products) {
		for (auto j : *i) {
			sum_products[j->product] += j->counter;
		}
	}
	bool flag = false;
	for (auto i : boxes) {
		if (sum_products[i] - sum_application[i] < info_products[i] / 2) {
			bool flag = true;
			break;
		}
	}
	if (!flag) {
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

void Storage::setStorage(std::vector<is::WholesaleBox*>& boxes) {
	for (auto i : boxes) {
		info_products.insert({ i, 10 });
	}
}

void Storage::applicationProcessing(is::Application* application) {
	applications[0].push_back(application);
}

is::Application* Storage::generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes) {
	is::Application* application = new is::Application(this, receiver, new is::List);
	std::map<is::WholesaleBox*, int64_t> sum_application;
	for (auto i : boxes) {
		sum_application.insert({ i, 0 });
	}
	for (auto i : applications[0]) {
		for (auto j : (*i->application)) {
			sum_application[j->product] += j->counter;
		}
	}
	std::map<is::WholesaleBox*, int64_t> sum_products;
	for (auto i : boxes) {
		sum_products.insert({ i, 0 });
	}
	for (auto i : products) {
		for (auto j : *i) {
			sum_products[j->product] += j->counter;
		}
	}
	for (auto i : boxes) {
		int64_t sum = info_products[i] / 2 - (sum_products[i] - sum_application[i]);
		if (sum > 0) {
			if (sum > info_products[i] / 2) {
				application->application->push_back(new is::ElemInList(i, info_products[i]));
			}
			else {
				application->application->push_back(new is::ElemInList(i, sum));
			}
		}
	}
	return application;
}
