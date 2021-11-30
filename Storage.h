#pragma once
#include "Building.h"
class Storage : public Building {
public:
	Storage() = default;
	Storage(std::vector<is::WholesaleBox*>& boxes);
	virtual void checkApplications() override;
	virtual void checkOrder(std::vector<Building*> buildings) override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Storage();
protected:
	virtual void createApplication(Building* receiver);
	virtual void sendApplication(is::Application* application, Building* receiver);
	virtual void receiveApplication(is::Application* application);
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
	std::vector<std::pair<is::WholesaleBox*, int64_t>> info_products;
	double coef_for_price;
};

