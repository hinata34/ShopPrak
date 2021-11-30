#pragma once
#include "Building.h"
class Trash : public Building {
public:
	Trash();
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buidlings) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Trash();
protected:
	virtual void receiveApplication(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
};

