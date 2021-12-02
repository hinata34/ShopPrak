#include "SuperStorage.h"

SuperStorage::SuperStorage(int64_t days) : Building(days){
	coef_for_price = 0.95;
	category = 3;
}

void SuperStorage::setStorage(std::vector<is::WholesaleBox*>& boxes) {
	for (auto i : boxes) {
		info_products.insert({ i, INT64_MAX });
		if (i->product->storage_life >= products.size()) {
			products[products.size() - 1]->push_back(new is::ElemInList(i, info_products[i]));
		}
		else {
			products[i->product->storage_life - 1]->push_back(new is::ElemInList(i, info_products[i]));
		}
	}
}

void SuperStorage::applicationProcessing(is::Application* application) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid(0, 5);
	applications[uid(gen)].push_back(application);
}

void SuperStorage::distributionProducts(std::vector<is::Application*>& new_applications) {
	for (auto i : applications[0]) {
		new_applications.push_back(new is::Application(i->receiver, i->customer, i->application));
	}
}
