#include "SuperStorage.h"

SuperStorage::SuperStorage(int64_t days) : Building(days){
	coef_for_price = 0.95;
	category = 3;
}

void SuperStorage::setStorage(std::vector<is::WholesaleBox*>& boxes) {
	for (auto i : boxes) {
		info_products.insert({ i, INT64_MAX });
		for (auto j : products) {
			j->push_back(new is::ElemInList(i, info_products[i]));
		}
	}
}

void SuperStorage::applicationProcessing(is::Application* application) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid(0, 4);
	applications[uid(gen) % applications.size()].push_back(application);
}

void SuperStorage::distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes) {
	for (auto i : applications[0]) {
		new_applications.push_back(new is::Application(i->receiver, i->customer, new is::List()));
		for (auto j : *i->application) {
			new_applications[new_applications.size() - 1]->application->push_back(new is::ElemInList(j->product, j->counter));
		}
	}
}
