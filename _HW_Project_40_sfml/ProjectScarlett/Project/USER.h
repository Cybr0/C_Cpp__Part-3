#pragma once
#include <iostream>
#include <string>
#include <vector>

enum accessRights {   // ��� ����������� ���� ������� ��� ������(����� �������)
	ar_admin = 1,
	ar_cashier,
	ar_default
};

class User {
public:
	// ������������.....
	User();
	User(std::string login, std::string password);
	User(std::string login, std::string password, std::string fullName);
	User(std::string login, std::string password, std::string fullName, accessRights rights);
	~User() {} // ����������
	 //�������
	std::string& getLogin();
	std::string& getPassword();
	std::string& getFullName();
	accessRights& getRights();
	// �������
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setFullName(std::string fullName);
	void setRights(accessRights rights);
protected:
	std::string login; // ����� ������������
	std::string password; // ������ ������������
	std::string fullName; // ��� ������������	accessRights rights; // ��� ������� (������������� / ������)
	accessRights rights;
};
