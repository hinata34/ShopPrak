#pragma once
#include "Config.h"
#include "Day.h"
class Building {
public:
	Building() = default;
	virtual void checkApplications() = 0; // ���������, ��� ����� ���������
	virtual void checkOrder(std::vector<Building*> buildings) = 0; // ���������, ��� ����� ��������
	virtual void updateDayInfo(Day* day) = 0; // �������� ���������� �� ���
	virtual ~Building() = default;
	int64_t getCategory();
protected:
	virtual void createApplication(Building* receiver); // �������� ������
	virtual void sendApplication(is::Application* application, Building* receiver); // �������� ������
	virtual void receiveApplication(is::Application* application); // ����� ������
	virtual void applicationProcessing(is::Application* application) = 0;
	virtual void sendProducts(is::Application* application) = 0; // �������� ���������
	virtual void receiveProducts(is::Application* application) = 0; // ����� ���������
	virtual is::Application* generateApplication(Building* receiver) = 0; // ��������� ������
	virtual void distributionProducts() = 0; // ������������� ���������

	std::map<Building*, is::Application*> today_applications; // �� ��� �� �������� �������
	std::vector<std::vector<is::Application*>> applications; // �� ��� �� ����������
	std::vector<is::List*> products; // �� ��� ����� ������
	std::vector<is::Application*> expected_applications; // ������, ������� �� �������
	int64_t category; // � ����� ��������� ��������� ������
};

