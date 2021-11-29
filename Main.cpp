#include "Shop.h"
#include "Storage.h"
#include "Trash.h"
#include "SuperStorage.h"
#include "Factory.h"
#include "Rules.h"
int main() {
	std::vector<is::WholesaleBox*> boxes;
	std::vector<Building*> buidlings;
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
		buidlings.push_back(shop_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Storage); ++i) {
		buidlings.push_back(storage_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::SuperStorage); ++i) {
		buidlings.push_back(superstorage_factory->createBuilding());
	}

	for (size_t i = 0; i < rules.getNumberOfBuilding(is::Builds::Trash); ++i) {
		buidlings.push_back(trash_factory->createBuilding());
	}

}