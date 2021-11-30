#pragma once
#include "Building.h"
class Storage : public Building {
public:
	Storage() = default;
	Storage(std::vector<is::WholesaleBox*>& boxes);
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
	std::vector<std::pair<is::WholesaleBox*, int64_t>> info_products;
	double coef_for_price;
};

