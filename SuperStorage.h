#pragma once
#include "Building.h"
class SuperStorage : public Building {
public:
	SuperStorage();
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buildings) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~SuperStorage() = default;
protected:
	virtual void applicationProcessing(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
	double coef_for_price;
};

