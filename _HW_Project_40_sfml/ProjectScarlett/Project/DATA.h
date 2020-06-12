#pragma once
#include "USER.h"
#include "FLIGHT.h"

#include "Textbox.h"

#include <fstream>
//#include <SFML/Graphics.hpp>

class Data
{
public:
	Data(); // ����������� �� ���������
	~Data(); // ���������� 
	Data& operator=(Data& obj); // �������� ������������
	friend std::ofstream& operator<<(std::ofstream& fout, Data& obj); // ������ � ����
	friend std::ifstream& operator>>(std::ifstream& fin, Data& obj); // ���������� �� �����
	std::vector<User>& getUser(); // ������� ��� ������������ (������ � ������)
	std::vector<Flight>& getFlight(); // ������� ��� ������������ (������ � ������)

	bool changePassword(std::string& login, Textbox& tbox); // ��������� ������ (����. ��� ������)
	void addCashier(); // ���������� ������� (����. ��� ������)
	bool deleteCashier(); // �������� ������� (����. ��� ������)
	bool changeCashierInfo(); // �������������� �������� (����. ��� ������)
	bool findFlight(); // ����� �� ������ (����. ��� ������ � �������)
	void availableFlight(); // ������ ��������x ������ (����. ��� �������)
	void sellTicket(); // ������� ������� (����. ��� �������)
	void cancelTicket(); // ������ ������� (����. ��� �������)
	void addFlight(); // ���������� ����� (����. ��� ������)
	void deleteFlight(); // �������� ����� (����. ��� ������)
	void changeFlight(); // �������������� ������ (����.��� ������)
	void salesReports();
	void save(); // ������� ��� ������������ ������ (������������ � main �)
	//void infoUser();
private:

	void FlightInfo(); // ��� (���������) ����� (����. ��� ������ ��� ����������� �������������)

	std::vector<Flight> flight;   // ��� �����
	std::vector<User> user; // ��� ������������
};