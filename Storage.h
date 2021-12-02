#pragma once
#include "Building.h"
class Storage : public Building {
public:
	Storage() = default;
	Storage(int64_t days);
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes) override;
	virtual void updateDayInfo(Day* day) override;
	void setStorage(std::vector<is::WholesaleBox*>& boxes);
	virtual ~Storage() = default;
protected:
	virtual void applicationProcessing(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes);
	virtual void distributionProducts(std::vector<is::Application*>& new_applications) override;
	std::map<is::WholesaleBox*, int64_t> info_products;
};

