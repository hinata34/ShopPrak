#pragma once
#include "Building.h"
class Shop : public Building {
public:
	Shop();
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buildings) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Shop();
protected:
	virtual void createApplication(Building* receiver);
	virtual void sendApplication(is::Application* application, Building* receiver);
	virtual void receiveApplication(is::Application* application);
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
};

