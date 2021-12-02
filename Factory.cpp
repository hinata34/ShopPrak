#include "Factory.h"

Building* ShopFactory::createBuilding(int64_t days) {
	return new Shop(days);
}

Building* TrashFactory::createBuilding(int64_t days) {
	return new Trash(days);
}

Building* StorageFactory::createBuilding(int64_t days) {
	return new Storage(days);
}

Building* SuperStorageFactory::createBuilding(int64_t days) {
	return new SuperStorage(days);
}
