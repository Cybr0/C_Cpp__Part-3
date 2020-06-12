#pragma once
#include "USER.h"
#include "FLIGHT.h"

#include "Textbox.h"

#include <fstream>
//#include <SFML/Graphics.hpp>

class Data
{
public:
	Data(); // Конструктор по умолчанию
	~Data(); // Деструктор 
	Data& operator=(Data& obj); // Оператор присваивания
	friend std::ofstream& operator<<(std::ofstream& fout, Data& obj); // Запись в файл
	friend std::ifstream& operator>>(std::ifstream& fin, Data& obj); // Считывание из файла
	std::vector<User>& getUser(); // Функция для Инкапцуляции (доступ к данным)
	std::vector<Flight>& getFlight(); // Функция для Инкапцуляции (доступ к данным)

	bool changePassword(std::string& login, Textbox& tbox); // Изменение пароля (функ. для Админа)
	void addCashier(); // Добавление Кассира (функ. для Админа)
	bool deleteCashier(); // Удаление Кассира (функ. для Админа)
	bool changeCashierInfo(); // Редактирование Кассиров (функ. для Админа)
	bool findFlight(); // Поиск по Рейсам (функ. для Админа и Кассира)
	void availableFlight(); // Список Доступныx Рейсов (функ. для Кассира)
	void sellTicket(); // Продажа Билетов (функ. для Кассира)
	void cancelTicket(); // Отмена Билетов (функ. для Кассира)
	void addFlight(); // Добавление Рейса (функ. для Админа)
	void deleteFlight(); // Удаление Рейса (функ. для Админа)
	void changeFlight(); // Редактирование Рейсов (функ.для Админа)
	void salesReports();
	void save(); // Функция для актуальности данных (используется в main е)
	//void infoUser();
private:

	void FlightInfo(); // Все (Абсолютно) Рейсы (функ. для Админа для внутреннего использования)

	std::vector<Flight> flight;   // Все рейсы
	std::vector<User> user; // Все Пользователи
};