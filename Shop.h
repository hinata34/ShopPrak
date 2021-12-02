#pragma once
#include "Building.h"
class Shop : public Building {
public:
	Shop() = default;
	Shop(int64_t days);
	virtual void checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes) override;
	virtual ~Shop() = default;
protected:
	virtual void receiveProducts(is::Application* application) override;
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes) override;
};

