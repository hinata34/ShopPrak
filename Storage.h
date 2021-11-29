#pragma once
#include "Building.h"
class Storage : public Building {
public:
	Storage();
	virtual void checkApplications() override;
	virtual void checkOrder() override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Storage();
protected:
	virtual bool createApplication(Building* receiver) override;
	virtual void sendApplication(Building* receiver) override;
	virtual void receiveApplication(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
	virtual int64_t getReputation(Building* building) override;
	std::vector<std::pair<WholesaleBox*, int64_t>> info_products;
	double coef_for_price;
};

