#pragma once
#include <iostream>
#include <string>
#include <vector>
class Ticket
{
public:
	// Конструкторы....
	Ticket();
	Ticket(std::string nameOfPassanger, std::string dataOfPassanger, char classType, int seatNumber, bool baggage, double price, bool sold);

	~Ticket(); //  Деструктор

	//   Геттеры
	std::string& getNameOfPassanger();
	std::string& getDataOfPassanger();
	char& getClassType();
	bool& getBaggage();
	double& getPrice();
	bool& getSold();
	int getSeatNumber() { return seatNumber; }

	// Сеттеры
	void setSeatNumber(int seatNum) { seatNumber = seatNum; }
	void setNameOfPassanger(std::string nameOfPassanger);
	void setDataOfPassanger(std::string dataOfPassanger);
	void setClassType(char classType);
	void setBaggage(bool baggage);
	void setPrice(double price);
	void setSold(bool sold);
private:
	std::string nameOfPassanger; //имя пассажира
	std::string dataOfPassanger; //паспорт
	char classType; // (Класс бронирования). Латинская буква, кодирующая класс мест в самолете. 
					//Пример:	A - первый класс,    B - бизнес класс,    C - экономический класс,	   X - не выбран;
	int seatNumber; //место
	bool baggage;
	double price;  // Цена Билета
	bool sold; // проверка(продан или нет)
};



class Flight // рейс
{
public:
	//  Конструкторы .......
	Flight();
	Flight(std::vector<Ticket> ticket);
	Flight(std::string airline, std::string flightNumber, std::string from_to,
		std::string date_from_to, std::string time_from_to,
		std::vector<Ticket> ticket, bool available);

	~Flight();  // Деструктор 

	// Геттеры
	std::string& getAirline();
	std::string& getFlightNumber();
	std::string& getFrom_to();
	std::string& getDate_from_to();
	std::string& getTime_from_to();
	std::vector<Ticket>& getTicket();
	bool getAvailable() { return available; }

	void addTicket(Ticket& ticket); // Добавление вектора тикетов
	void setAirline(std::string airline);  // Сеттеры
	void setFlightNumber(std::string flightNumber);
	void setFrom_to(std::string from_to);
	void setDate_from_to(std::string date_from_to);
	void setTime_from_to(std::string time_from_to);
	void setTicket(std::vector<Ticket> ticket);
	void setAvailable(bool ok) { available = ok; }
	int seatNumberTicket = 1; // Переменная определяющяя номер места для каждого билета (при добавлении)
private:
	bool available; //      Доступный / Не Доступный   Рейс
	std::string airline; //авиакомпания
	std::string flightNumber; // номер рейса
	std::string from_to; // Пункт отправления(origin)/назначения(destination)
	std::string date_from_to; // месяц/год
	std::string time_from_to; // Время вылета/прилета
	std::vector<Ticket> ticket; // количество билетов
};

