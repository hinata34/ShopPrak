#include "Shop.h"
#include "Storage.h"
Shop::Shop(int64_t days) : Building(days) {
	category = 1;
}

void Shop::checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes) {
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

void Shop::receiveProducts(is::Application* application) {
	is::Application* new_app = new is::Application(application->receiver, application->customer, new is::List());
	for (auto i : *application->application) {
		new_app->application->push_back(new is::ElemInList(i->product, i->counter));
	}
	debug.received.push_back(*new_app);
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
	return;
}

is::Application* Shop::generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid_product(0, 9);
	std::uniform_int_distribution<> uid_counter(1, 4);
	is::Application* application = new is::Application(this, receiver, new is::List());
	for (auto i : boxes) {
		if (uid_product(gen) % 10 == 0) {
			uid_counter = std::uniform_int_distribution<>{static_cast<int>(static_cast<Storage*>(receiver)->getInfoProducts(i) / 10), 
														  static_cast<int>(static_cast<Storage*>(receiver)->getInfoProducts(i) / 6)};
			application->application->push_back(new is::ElemInList(i, uid_counter(gen)));
		}
	}
	return application;
}