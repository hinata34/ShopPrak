#pragma once
#include "Config.h"
#include "Day.h"
class Building {
public:
	Building() = default;
	virtual void checkApplications(); // ���������, ��� ����� ���������
	virtual void checkOrder(std::vector<Building*> buildings, std::vector<is::WholesaleBox*> boxes); // ���������, ��� ����� ��������
	virtual void updateDayInfo(Day* day) = 0; // �������� ���������� �� ���
	virtual ~Building() = default;
	int64_t getCategory();
protected:
	virtual void createApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes); // �������� ������
	virtual void sendApplication(is::Application* application, Building* receiver); // �������� ������
	virtual void receiveApplication(is::Application* application); // ����� ������
	virtual void applicationProcessing(is::Application* application);
	virtual void sendProducts(is::Application* application); // �������� ���������
	virtual void receiveProducts(is::Application* application) ; // ����� ���������
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*> boxes); // ��������� ������
	virtual void distributionProducts(); // ������������� ���������

	std::vector<std::vector<is::Application*>> applications; // �� ��� �� ����������
	std::vector<is::List*> products; // �� ��� ����� ������
	std::vector<is::Application*> expected_applications; // ������, ������� �� �������
	int64_t category; // � ����� ��������� ��������� ������
};

