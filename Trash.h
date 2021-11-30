#pragma once
#include "Building.h"
class Trash : public Building {
public:
	Trash();
	virtual void checkApplications() override;
	virtual void checkOrder() override;
	virtual void updateDayInfo(Day* day) override;
	virtual ~Trash();
protected:
	virtual bool createApplication(Building* receiver) override;
	virtual void sendApplication(Building* receiver) override;
	virtual void receiveApplication(is::Application* application) override;
	virtual void sendProducts(is::Application* application) override;
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver) override;
	virtual void distributionProducts() override;
};

