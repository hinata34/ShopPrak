#pragma once
#include "Config.h"
class Rules {
public:
	Rules() = default;
	Rules(std::vector<is::WholesaleBox*>& boxes);
	int64_t getNumberOfBuilding(is::Builds type);
	void setNumberOfBuilding(is::Builds type, int64_t number);
	~Rules() = default;
private:
	std::vector<int64_t> numbers_of_buildings;
	int64_t num_of_products_;
};

