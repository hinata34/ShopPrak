#include "Building.h"

Building::Building(int64_t days) {
	applications.resize(days);
	products.resize(days + 1);
	for (auto& i : products) {
		i = new is::List();
	}
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
	/*for (auto i : applications[0]) {
		try {
			if (i->application->size() != 0) {
				for (auto j : *i->application) {
					delete j;
				}
			}
			delete i;
		} catch(...) {
			;
		}
	}*/
	applications.erase(applications.begin());
	for (auto i : *products[0]) {
		debug.garbage->push_back(new is::ElemInList(i->product, i->counter));
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

void Building::setDebugInfoSpended(int64_t spended_money) {
	debug.spended_money += spended_money;
}

void Building::createApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) {
	this->sendApplication(this->generateApplication(receiver, boxes), receiver);
}

void Building::sendApplication(is::Application* application, Building* receiver) {
	if (!application->application->empty()) {
		expected_applications.push_back(application);
		receiver->receiveApplication(application);
	}
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
		int64_t day = 0;
		for (auto j : products) {
			++day;
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
						debug.earned_money += static_cast<int64_t>(product->counter * product->product->price * coef_for_price * 
																  ((product->product->product->storage_life / 5 >= day && category == 2) ? 0.7 : 1));
						product->counter = 0;
						delete product;
						j->erase(std::remove(j->begin(), j->end(), product), j->end());
						break;
					}
					else {
						product->counter -= i->counter;
						debug.earned_money += static_cast<int64_t>(i->counter * product->product->price * coef_for_price *
																  ((product->product->product->storage_life / 5 >= day && category == 2) ? 0.7 : 1));
						i->counter = 0;
						break;
					}
				}
			}
		}
	}
	application->receiver->setDebugInfoSpended(debug.earned_money);
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

