#pragma once
#include "Config.h"
class Rules {
public:
	int64_t getCountType();
	int64_t getBound();
	void CreateRules(std::vector<WholesaleBox*>& boxes);
	void setNumberOfBuilding(is::Builds type, int64_t number);
	int64_t getNumberOfBuilding(is::Builds type);
private:
	std::vector<int64_t> numbers_of_buildings;
	int64_t num_of_products_;
	int64_t num_of_types_;
	int64_t max_bound_;
};

