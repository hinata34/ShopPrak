#include "Storage.h"

Storage::Storage(std::vector<is::WholesaleBox*>& boxes) : Building(){
	for (auto i : boxes) {
		info_products.push_back({ i, 10 });
	}
	coef_for_price = 1.1;
}

void Storage::applicationProcessing(is::Application* application) {
	applications[0].push_back(application);
}
