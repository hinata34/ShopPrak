#pragma once
#include "Building.h"
class SuperStorage : public Building {
public:
	SuperStorage() = default;
	SuperStorage(int64_t days);
	virtual void updateDayInfo(Day* day) override;
	void setStorage(std::vector<is::WholesaleBox*>& boxes);
	virtual ~SuperStorage() = default;
protected:
	virtual void applicationProcessing(is::Application* application) override;
	virtual void distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes) override;
	std::map<is::WholesaleBox*, int64_t> info_products;
};

