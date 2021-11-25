#pragma once
#include "Buildings.h"
#include "Shop.h"
#include "Storage.h"
#include "Trash.h"
#include "SuperStorage.h"
class Factory {
public:
	Factory();
	virtual Building* createBuilding() = 0;
	virtual ~Factory();
};

class ShopFactory : public Factory {
public:
	Building* createBuilding() override; // Создание объекта Shop
};

class TrashFactory : public Factory {
	Building* createBuilding() override; // Создание объекта Trash
};

class StorageFactory : public Factory {
	Building* createBuilding() override; // Создание объекта Storage
};

class SuperStorageFactory : public Factory {
	Building* createBuilding() override; // Создание объекта SuperStorage
};