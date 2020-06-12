#include "USER.h"

User::User() :User("Login", "Password", "FullName", accessRights(2))
{
}

User::User(std::string login, std::string password) : User(login, password, "FullName", accessRights(2))
{
}

User::User(std::string login, std::string password, std::string fullName) :
	User(login, password, fullName, accessRights(2))
{
}

User::User(std::string login, std::string password, std::string fullName, accessRights rights)
{
	this->login = login;
	this->password = password;
	this->fullName = fullName;
	this->rights = rights;
}

std::string& User::getLogin()
{
	return login;
}

std::string& User::getPassword()
{
	return password;
}

std::string& User::getFullName()
{
	return fullName;
}

accessRights& User::getRights()
{
	return rights;
}

void User::setLogin(std::string login)
{
	this->login = login;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

void User::setFullName(std::string fullName)
{
	this->fullName = fullName;
}

void User::setRights(accessRights rights)
{
	this->rights = rights;
}