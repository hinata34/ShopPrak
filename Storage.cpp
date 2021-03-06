#include "Storage.h"

Storage::Storage(int64_t days) : Building(days){
	category = 2;
	coef_for_price = 1.2;
}

void Storage::checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes) {
	std::map<is::WholesaleBox*, int64_t> sum_application;
	for (auto i : boxes) {
		sum_application.insert({ i, 0 });
	}
	for (auto i : applications[0]) {
		for (auto j : *i->application) {
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
		    flag = true;
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
	std::uniform_int_distribution<> uid(0, 5);
	for (auto i : boxes) {
		if (i->product->name == "Bananas") {
			uid = std::uniform_int_distribution<>{ 500, 1000 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Apples") {
			uid = std::uniform_int_distribution<>{ 500, 1000 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Tomatoes") {
			uid = std::uniform_int_distribution<>{ 500, 700 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Bread") {
			uid = std::uniform_int_distribution<>{ 2000, 2500 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Cucumbers") {
			uid = std::uniform_int_distribution<>{ 700, 1000 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Potatoes") {
			uid = std::uniform_int_distribution<>{ 500, 750 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Eggs") {
			uid = std::uniform_int_distribution<>{ 100, 200 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Oil") {
			uid = std::uniform_int_distribution<>{ 400, 600 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Orange") {
			uid = std::uniform_int_distribution<>{ 50, 60 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Pork") {
			uid = std::uniform_int_distribution<>{ 90, 100 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Sugar") {
			uid = std::uniform_int_distribution<>{ 100, 150 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Salmon") {
			uid = std::uniform_int_distribution<>{ 20, 70 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Caviar") {
			uid = std::uniform_int_distribution<>{ 5, 10 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Tangerines") {
			uid = std::uniform_int_distribution<>{ 700, 800 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Kiwi") {
			uid = std::uniform_int_distribution<>{ 540, 600 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Milk") {
			uid = std::uniform_int_distribution<>{ 800, 900 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->name == "Cheese") {
			uid = std::uniform_int_distribution<>{ 90, 100 };
			info_products.insert({ i, uid(gen) });
		}
		if (i->product->storage_life >= products.size()) {
			products[products.size() - 1]->push_back(new is::ElemInList(i, info_products[i]));
		}
		else {
			products[i->product->storage_life]->push_back(new is::ElemInList(i, info_products[i]));
		}
	}
}

int64_t Storage::getInfoProducts(is::WholesaleBox* product) {
	return info_products[product];
}

void Storage::applicationProcessing(is::Application* application) {
	applications[0].push_back(application);
}

void Storage::receiveProducts(is::Application* application) {
	is::Application* new_app = new is::Application(application->receiver, application->customer, new is::List());
	for (auto i : *application->application) {
		new_app->application->push_back(new is::ElemInList(i->product, i->counter));
	}
	debug.received.push_back(*new_app);
	for (auto i : *application->application) {
		bool flag = true;
		for (auto j : *products[i->product->product->storage_life - 1 >= products.size() ?
			products.size() - 1 : i->product->product->storage_life - 1]) {
			if (j->product == i->product) {
				j->counter += i->counter;
				flag = false;
				break;
			}
		}
		if (flag) {
			if (i->product->product->storage_life >= products.size()) {
				products[products.size() - 1]->push_back(new is::ElemInList(i->product, i->counter));
			}
			else {
				products[i->product->product->storage_life - 1]->push_back(new is::ElemInList(i->product, i->counter));
			}
		}
	}
	for (auto i : expected_applications) {
		if (i->customer == application->customer) {
			for (auto j : *i->application) {
				delete j;
			}
			expected_applications.erase(std::remove(expected_applications.begin(), expected_applications.end(), i),
										expected_applications.end());
			delete i;
			break;
		}
	}
}

is::Application* Storage::generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) {
	is::Application* application = new is::Application(this, receiver, new is::List);
	std::map<is::WholesaleBox*, int64_t> sum_application;
	for (auto i : boxes) {
		sum_application.insert({ i, 0 });
	}
	for (auto i : applications[0]) {
		for (auto j : *i->application) {
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
				application->application->push_back(new is::ElemInList(i, sum + info_products[i] / 4));
			}
		}
	}
	return application;
}

void Storage::distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes) {
	std::map<is::WholesaleBox*, std::pair<int64_t, int64_t>> sum_application;
	for (auto i : boxes) {
		sum_application.insert({ i, {0, 0} });
	}
	for (auto i : applications[0]) {
		new_applications.push_back(new is::Application(i->receiver, i->customer, new is::List()));
		for (auto j : *i->application) {
			sum_application[j->product].first += j->counter;
			++sum_application[j->product].second;
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
	std::map<is::WholesaleBox*, std::vector<std::pair<int64_t, Building*>>> sorted;
	for (auto i : boxes) {
		std::vector<std::pair<int64_t, Building*>> tmp;
		for (auto j : applications[0]) {
			for (auto q : *j->application) {
				if (i == q->product) {
					tmp.push_back({ q->counter, j->receiver});
				}
			}
		}
		std::sort(tmp.begin(), tmp.end(), [](auto a, auto b) {
			return a.first < b.first;
		});
		sorted[i] = tmp;
	}
	for (auto i : boxes) {
		if (sum_application[i].first <= sum_products[i]) {
			for (auto j : sorted[i]) {
				for (auto q : new_applications) {
					if (q->receiver == j.second) {
						q->application->push_back(new is::ElemInList(i, j.first));
					}
				}
			}
		} else {
			for (auto j : sorted[i]) {
				for (auto q : new_applications) {
					if (q->receiver == j.second) {
						if (sum_products[i] / sum_application[i].second > j.first) {
							q->application->push_back(new is::ElemInList(i, j.first));
							sum_products[i] -= j.first;
							--sum_application[i].second;
						} else {
							q->application->push_back(new is::ElemInList(i, sum_products[i] / sum_application[i].second));
							sum_products[i] -= sum_products[i] / sum_application[i].second;
							--sum_application[i].second;
						}
					}
				}
			}
		}
	}
}
