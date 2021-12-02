#pragma once
#include "Building.h"
class Trash : public Building {
public:
	Trash() = default;
	Trash(int64_t days);
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buidlings, std::vector<is::WholesaleBox*> boxes) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Trash();
protected:
	virtual void receiveApplication(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes) override;
	virtual void distributionProducts() override;
};

