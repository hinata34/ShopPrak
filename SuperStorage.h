#pragma once
#include "Building.h"
class SuperStorage : public Building {
public:
	SuperStorage() = default;
	SuperStorage(int64_t days);
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~SuperStorage() = default;
protected:
	virtual void applicationProcessing(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes);
	virtual void distributionProducts() override;
	double coef_for_price;
};

