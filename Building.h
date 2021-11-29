#pragma once
#include "Config.h"
#include "Day.h"
class Building {
public:
	Building();
	Building(std::vector<Building*> buildings);
	virtual void checkApplications() = 0; // Проверяем, что нужно отправить
	virtual void checkOrder() = 0; // Проверяем, что нужно заказать
	virtual void updateDayInfo(Day* day) = 0; // Передает информацию по дню
	virtual ~Building();
protected:
	virtual bool createApplication(Building* receiver) = 0; // Создание заказа
	virtual void sendApplication(Building* receiver) = 0; // Отправка заказа
	virtual void receiveApplication(is::Application* application) = 0; // Прием заказа
	virtual void sendProducts(is::Application* application) = 0; // Отправка продуктов
	virtual void receiveProducts(is::Application* application) = 0; // Прием продуктов
	virtual is::Application* generateApplication(Building* receiver) = 0; // Генерация заказа
	virtual void distributionProducts() = 0; // Распределение продуктов
	virtual int64_t getReputation(Building* building) = 0; // Возвращает, как он относится к building 

	std::map<Building*, is::Application*> today_applications; // То что мы заказали сегодня
	std::vector<std::vector<is::Application*>> applications; // То что мы отправляем
	std::vector<is::List> products; // То что лежит складе
	std::vector<is::Application*> expected_applications; // Заказы, которые мы ожидаем
	std::map<Building*, int64_t> reputations; // Как мы относимся к каждому объекту
	int64_t category; // К какой категории относится объект
	std::vector<Building*> buildings_offer; // У кого мы можем заказывать
};

