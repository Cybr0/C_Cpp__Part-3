#pragma once
#include <iostream>
#include <string>
#include <vector>
class Ticket
{
public:
	// ������������....
	Ticket();
	Ticket(std::string nameOfPassanger, std::string dataOfPassanger, char classType, int seatNumber, bool baggage, double price, bool sold);

	~Ticket(); //  ����������

	//   �������
	std::string& getNameOfPassanger();
	std::string& getDataOfPassanger();
	char& getClassType();
	bool& getBaggage();
	double& getPrice();
	bool& getSold();
	int getSeatNumber() { return seatNumber; }

	// �������
	void setSeatNumber(int seatNum) { seatNumber = seatNum; }
	void setNameOfPassanger(std::string nameOfPassanger);
	void setDataOfPassanger(std::string dataOfPassanger);
	void setClassType(char classType);
	void setBaggage(bool baggage);
	void setPrice(double price);
	void setSold(bool sold);
private:
	std::string nameOfPassanger; //��� ���������
	std::string dataOfPassanger; //�������
	char classType; // (����� ������������). ��������� �����, ���������� ����� ���� � ��������. 
					//������:	A - ������ �����,    B - ������ �����,    C - ������������� �����,	   X - �� ������;
	int seatNumber; //�����
	bool baggage;
	double price;  // ���� ������
	bool sold; // ��������(������ ��� ���)
};



class Flight // ����
{
public:
	//  ������������ .......
	Flight();
	Flight(std::vector<Ticket> ticket);
	Flight(std::string airline, std::string flightNumber, std::string from_to,
		std::string date_from_to, std::string time_from_to,
		std::vector<Ticket> ticket, bool available);

	~Flight();  // ���������� 

	// �������
	std::string& getAirline();
	std::string& getFlightNumber();
	std::string& getFrom_to();
	std::string& getDate_from_to();
	std::string& getTime_from_to();
	std::vector<Ticket>& getTicket();
	bool getAvailable() { return available; }

	void addTicket(Ticket& ticket); // ���������� ������� �������
	void setAirline(std::string airline);  // �������
	void setFlightNumber(std::string flightNumber);
	void setFrom_to(std::string from_to);
	void setDate_from_to(std::string date_from_to);
	void setTime_from_to(std::string time_from_to);
	void setTicket(std::vector<Ticket> ticket);
	void setAvailable(bool ok) { available = ok; }
	int seatNumberTicket = 1; // ���������� ������������ ����� ����� ��� ������� ������ (��� ����������)
private:
	bool available; //      ��������� / �� ���������   ����
	std::string airline; //������������
	std::string flightNumber; // ����� �����
	std::string from_to; // ����� �����������(origin)/����������(destination)
	std::string date_from_to; // �����/���
	std::string time_from_to; // ����� ������/�������
	std::vector<Ticket> ticket; // ���������� �������
};

