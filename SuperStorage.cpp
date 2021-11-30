#include "SuperStorage.h"

SuperStorage::SuperStorage() : Building(){
	coef_for_price = 0.95;
}

void SuperStorage::applicationProcessing(is::Application* application) {
	std::mt19937_64 gen(time(0));
	std::uniform_int_distribution<> uid(0, 5);
	applications[uid(gen)].push_back(application);
}
