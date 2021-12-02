#include "Building.h"

Building::Building(int64_t days) {
	applications.resize(days);
	products.resize(days + 1);
}

void Building::checkApplications(std::vector<is::WholesaleBox*>& boxes) {
	debug.earned_money = 0;
	debug.spended_money = 0;
	debug.received.clear();
	debug.sended.clear();
	debug.garbage = new is::List();
	if (applications[0].empty()) {
		applications.erase(applications.begin());
		for (auto i : *products[0]) {
			delete i;
		}
		products.erase(products.begin());
		return;
	}
	std::vector<is::Application*> new_applicatoins;
	distributionProducts(new_applicatoins, boxes);
	for (auto i : new_applicatoins) {
		this->sendProducts(i);
		delete i;
	}
	for (auto i : applications[0]) {
		if (i->application->size() != 0) {
			for (auto j : *i->application) {
				delete j;
			}
		}
		delete i;
	}
	applications.erase(applications.begin());
	for (auto i : *products[0]) {
		delete i;
	}
	products.erase(products.begin());
}

void Building::checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes) {
	return;
}

int64_t Building::getCategory() {
	return category;
}

is::DebugInfo Building::getDebugInfo() {
	return debug;
}

void Building::createApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) {
	this->sendApplication(this->generateApplication(receiver, boxes), receiver);
}

void Building::sendApplication(is::Application* application, Building* receiver) {
	expected_applications.push_back(application);
	receiver->receiveApplication(application);
}

void Building::receiveApplication(is::Application* application) {
	applicationProcessing(application);
}

void Building::applicationProcessing(is::Application* application) {
	return;
}

void Building::sendProducts(is::Application* application) {
	application->receiver->receiveProducts(application);
	debug.sended.push_back(*application);
	for (auto i : *application->application) {
		for (auto j : products) {
			if (i->counter == 0) {
				break;
			}
			for (auto product : *j) {
				if (i->counter == 0) {
					break;
				}
				if (i->product == product->product) {
					if (i->counter >= product->counter) {
						i->counter -= product->counter;
						product->counter = 0;
						delete product;
						j->erase(std::remove(j->begin(), j->end(), product), j->end());
						break;
					}
					else {
						product->counter -= i->counter;
						i->counter = 0;
						break;
					}
				}
			}
		}
	}
	for (auto i : *application->application) {
		delete i;
	}
	application->application->resize(0);
}

void Building::receiveProducts(is::Application* application) {
	return;
}

is::Application* Building::generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) {
	return nullptr;
}

void Building::distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes) {
	return;
}

