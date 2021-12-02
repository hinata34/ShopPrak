#pragma once
#include "Building.h"
#include "Shop.h"
#include "Storage.h"
#include "SuperStorage.h"
class Factory {
public:
	Factory() = default;
	virtual Building* createBuilding(int64_t days) = 0;
	virtual ~Factory() = default;
};

class ShopFactory : public Factory {
public:
	Building* createBuilding(int64_t days) override; // �������� ������� Shop
};

class StorageFactory : public Factory {
public:
	Building* createBuilding(int64_t days) override; // �������� ������� Storage
};

class SuperStorageFactory : public Factory {
public:
	Building* createBuilding(int64_t days) override; // �������� ������� SuperStorage
};