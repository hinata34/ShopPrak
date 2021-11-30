#include "Building.h"

void Building::checkOrder(std::vector<Building*> buildings){
	return;
}

int64_t Building::getCategory() {
	return category;
}

void Building::createApplication(Building* receiver) {
	this->sendApplication(this->generateApplication(receiver), receiver);
}

void Building::sendApplication(is::Application* application, Building* receiver) {
	expected_applications.push_back(application);
	receiver->receiveApplication(application);
}

void Building::receiveApplication(is::Application* application) {
	applicationProcessing(application);
}
