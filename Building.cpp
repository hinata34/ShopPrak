#include "Building.h"

Building::Building(int64_t days) {
	applications.resize(days);
	products.resize(days);
}

void Building::checkApplications() {
	if (applications[0].empty()) {
		applications.erase(applications.begin());
		return;
	}

}

void Building::checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes) {
	return;
}

int64_t Building::getCategory() {
	return category;
}

void Building::createApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes) {
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
	return;
}

void Building::receiveProducts(is::Application* application) {
	return;
}

is::Application* Building::generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes) {
	return nullptr;
}

void Building::distributionProducts() {
	return;
}
