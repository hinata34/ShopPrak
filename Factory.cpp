#include "Factory.h"

Building* ShopFactory::createBuilding() {
	return new Shop();
}

Building* TrashFactory::createBuilding() {
	return new Trash();
}

Building* StorageFactory::createBuilding() {
	return new Storage();
}

Building* SuperStorageFactory::createBuilding() {
	return new SuperStorage();
}
