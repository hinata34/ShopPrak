#include "Storage.h"

Storage::Storage(std::vector<is::WholesaleBox*>& boxes) {
	for (auto i : boxes) {
		info_products.push_back({ i, 10 });
	}
}
