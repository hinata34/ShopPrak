#pragma once
#include "Config.h"
class Building {
public:
	Building() = default;
	Building(int64_t days);
	virtual void checkApplications(std::vector<is::WholesaleBox*>& boxes); // ���������, ��� ����� ���������
	virtual void checkOrder(std::vector<Building*>& buildings, std::vector<is::WholesaleBox*>& boxes); // ���������, ��� ����� ��������
	virtual ~Building() = default;
	int64_t getCategory();
	is::DebugInfo getDebugInfo();
	void setDebugInfoSpended(int64_t spended_money);
protected:
	virtual void createApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes); // �������� ������
	virtual void sendApplication(is::Application* application, Building* receiver); // �������� ������
	virtual void receiveApplication(is::Application* application); // ����� ������
	virtual void applicationProcessing(is::Application* application);
	virtual void sendProducts(is::Application* application); // �������� ���������
	virtual void receiveProducts(is::Application* application) ; // ����� ���������
	virtual is::Application* generateApplication(Building* receiver, std::vector<is::WholesaleBox*>& boxes); // ��������� ������
	virtual void distributionProducts(std::vector<is::Application*>& new_applications, std::vector<is::WholesaleBox*>& boxes); // ������������� ���������

	std::vector<std::vector<is::Application*>> applications; // �� ��� �� ����������
	std::vector<is::List*> products; // �� ��� ����� ������
	std::vector<is::Application*> expected_applications; // ������, ������� �� �������
	int64_t category; // � ����� ��������� ��������� ������
	double coef_for_price;
	is::DebugInfo debug;
};
