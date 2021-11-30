#pragma once
#include "Config.h"
class Rules {
public:
	Rules() = default;
	Rules(std::vector<is::WholesaleBox*>& boxes);
	int64_t getCountType();
	int64_t getBound();
	int64_t getNumberOfBuilding(is::Builds type);
	void setNumberOfBuilding(is::Builds type, int64_t number);
private:
	std::vector<int64_t> numbers_of_buildings;
	int64_t num_of_products_;
	int64_t num_of_types_;
	int64_t max_bound_;
};

