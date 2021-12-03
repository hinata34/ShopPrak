#pragma once
#include "Config.h"
class Building {
public:
	Building() = default;
	Building(int64_t days);
	virtual void checkApplications(std::vector<is::WholesaleBox*>& boxes); // Проверяем, что нужно отправить
	virtual void checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes); // Проверяем, что нужно заказать
	virtual ~Building() = default;
	int64_t getCategory();
	is::DebugInfo getDebugInfo();
	void setDebugInfoSpended(int64_t spended_money);
protected:
	virtual void createApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes); // Создание заказа
	virtual void sendApplication(is::Application* application, Building* receiver); // Отправка заказа
	virtual void receiveApplication(is::Application* application); // Прием заказа
	virtual void applicationProcessing(is::Application* application);
	virtual void sendProducts(is::Application* application); // Отправка продуктов
	virtual void receiveProducts(is::Application* application) ; // Прием продуктов
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes); // Генерация заказа
	virtual void distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes); // Распределение продуктов

	std::vector<std::vector<is::Application*>> applications; // То что мы отправляем
	std::vector<is::List*> products; // То что лежит складе
	std::vector<is::Application*> expected_applications; // Заказы, которые мы ожидаем
	int64_t category; // К какой категории относится объект
	double coef_for_price;
	is::DebugInfo debug;
};
