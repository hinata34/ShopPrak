#pragma once
#include "Config.h"
#include "Day.h"
class Building {
public:
	Building() = default;
	virtual void checkApplications() = 0; // Проверяем, что нужно отправить
	virtual void checkOrder(std::vector<Building*> buildings) = 0; // Проверяем, что нужно заказать
	virtual void updateDayInfo(Day* day) = 0; // Передает информацию по дню
	virtual ~Building() = default;
	int64_t getCategory();
protected:
	virtual void createApplication(Building* receiver); // Создание заказа
	virtual void sendApplication(is::Application* application, Building* receiver); // Отправка заказа
	virtual void receiveApplication(is::Application* application); // Прием заказа
	virtual void applicationProcessing(is::Application* application) = 0;
	virtual void sendProducts(is::Application* application) = 0; // Отправка продуктов
	virtual void receiveProducts(is::Application* application) = 0; // Прием продуктов
	virtual is::Application* generateApplication(Building* receiver) = 0; // Генерация заказа
	virtual void distributionProducts() = 0; // Распределение продуктов

	std::map<Building*, is::Application*> today_applications; // То что мы заказали сегодня
	std::vector<std::vector<is::Application*>> applications; // То что мы отправляем
	std::vector<is::List*> products; // То что лежит складе
	std::vector<is::Application*> expected_applications; // Заказы, которые мы ожидаем
	int64_t category; // К какой категории относится объект
};

