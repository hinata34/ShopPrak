#include "SuperStorage.h"

SuperStorage::SuperStorage(int64_t days) : Building(days){
	coef_for_price = 0.95;
	category = 3;
}

void SuperStorage::applicationProcessing(is::Application* application) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid(0, 5);
	applications[uid(gen)].push_back(application);
}
