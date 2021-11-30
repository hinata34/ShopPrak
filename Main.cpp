#include "Shop.h"
#include "Storage.h"
#include "Trash.h"
#include "SuperStorage.h"
#include "Factory.h"
#include "Rules.h"


int main() {
	std::vector<is::WholesaleBox*> boxes;
	std::vector<Building*> buildings;
	boxes.resize(4);
	Rules rules(boxes);
	rules.setNumberOfBuilding(is::Builds::Trash, 1);
	rules.setNumberOfBuilding(is::Builds::Shop, 1);
	rules.setNumberOfBuilding(is::Builds::Storage, 1);
	rules.setNumberOfBuilding(is::Builds::SuperStorage, 1);

	ShopFactory* shop_factory = new ShopFactory();
	TrashFactory* trash_factory = new TrashFactory();
	StorageFactory* storage_factory = new StorageFactory();
	SuperStorageFactory* superstorage_factory = new SuperStorageFactory();

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Shop); ++i) {
		buildings.push_back(shop_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Storage); ++i) {
		buildings.push_back(storage_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::SuperStorage); ++i) {
		buildings.push_back(superstorage_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Trash); ++i) {
		buildings.push_back(trash_factory->createBuilding());
	}

	int n = 30, m, k;

	//std::cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {

		//начало дня
		
		//утро
		for (int j = 0; j < buildings.size(); ++j) {
			buildings[i]->checkApplications(); //отправляем все товары у всех buildings
		}

		//в течении дня делаем заказы
		for (int j = 0; j < buildings.size(); ++j) {
			buildings[i]->checkOrder();
		}

	}

}