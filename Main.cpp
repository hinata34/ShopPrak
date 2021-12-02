#include "Shop.h"
#include "Storage.h"
#include "SuperStorage.h"
#include "Factory.h"
#include "Rules.h"


int main() {
	int64_t days, shops, products;
	std::vector<is::WholesaleBox*> boxes;
	std::vector<Building*> buildings;
	std::cin >> days >> shops >> products;
	boxes.resize(products);
	Rules rules(boxes);
	rules.setNumberOfBuilding(is::Builds::Shop, shops);
	rules.setNumberOfBuilding(is::Builds::Storage, 1);
	rules.setNumberOfBuilding(is::Builds::SuperStorage, 1);

	ShopFactory* shop_factory = new ShopFactory();
	StorageFactory* storage_factory = new StorageFactory();
	SuperStorageFactory* superstorage_factory = new SuperStorageFactory();

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Shop); ++i) {
		buildings.push_back(shop_factory->createBuilding(days));
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Storage); ++i) {
		buildings.push_back(storage_factory->createBuilding(days));
		static_cast<Storage*>(buildings[buildings.size() - 1])->setStorage(boxes);
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::SuperStorage); ++i) {
		buildings.push_back(superstorage_factory->createBuilding(days));
		static_cast<SuperStorage*>(buildings[buildings.size() - 1])->setStorage(boxes);
	}

	for (int i = 0; i < days; ++i) {

		//начало дня
		
		//утро
		for (auto build : buildings) {
			build->checkApplications(boxes);
		}

		//в течении дня делаем заказы
		for (auto build : buildings) {
			build->checkOrder(buildings, boxes);
		}

	}

}