#pragma once
#include <string>

class Student
{
public:
	Student();
	~Student();
	void Name(std::string data);
	std::string Name();
	void Date(std::string);
	std::string Date();
	void Group(std::string);
	std::string Group();
private:
	std::string name;
	std::string birthDate;
	std::string group;
};

