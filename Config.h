#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>  
#include <ctime>  

struct Product;
struct WholesaleBox;
struct ElemInList;
struct Application;

class Building;
class Rules;

namespace is {
	enum Builds {
		Shop,
		Storage,
		SuperStorage,
		Trash
	};

	struct Product {
		std::string name;
		int64_t price_per_kg, package_size;
		int32_t storage_life;
		Product(std::string name, int64_t price_per_kg,
			int64_t package_size, int32_t storage_life) {
			this->name = name;
			this->price_per_kg = price_per_kg;
			this->package_size = package_size;
			this->storage_life = storage_life;
		}
	};

	struct WholesaleBox {
		Product* product;
		int64_t price;
		WholesaleBox(Product* product, int64_t price) {
			this->product = product;
			this->price = price;
		}
	};

	struct ElemInList {
		WholesaleBox* product;
		int64_t counter;
		ElemInList(WholesaleBox* product, int64_t counter) {
			this->product = product;
			this->counter = counter;
		}
	};

	typedef std::vector<is::ElemInList*> List;

	struct Application {
		Building* receiver, * customer;
		int64_t number_of_application;
		List* application;
	};

	struct ShopApplication {
		Application* application;
		int32_t number;
	};
}
