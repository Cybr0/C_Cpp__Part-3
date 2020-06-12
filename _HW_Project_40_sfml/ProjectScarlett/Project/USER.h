#pragma once
#include <iostream>
#include <string>
#include <vector>

enum accessRights {   // Для определения типа доступа для Узеров(Права доступа)
	ar_admin = 1,
	ar_cashier,
	ar_default
};

class User {
public:
	// Конструкторы.....
	User();
	User(std::string login, std::string password);
	User(std::string login, std::string password, std::string fullName);
	User(std::string login, std::string password, std::string fullName, accessRights rights);
	~User() {} // Деструктор
	 //Геттеры
	std::string& getLogin();
	std::string& getPassword();
	std::string& getFullName();
	accessRights& getRights();
	// Сеттеры
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setFullName(std::string fullName);
	void setRights(accessRights rights);
protected:
	std::string login; // Логин Пользователя
	std::string password; // Пароль Пользователя
	std::string fullName; // Имя Пользователя	accessRights rights; // Тип Доступа (Админимтратор / Кассир)
	accessRights rights;
};
