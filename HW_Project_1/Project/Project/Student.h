#pragma once
#include <string>
class Student
{
public:
	void SetName(std::string);
	void SetBirthDay(std::string);
	void SetGroup(std::string);
	std::string GetName();
	std::string GetBirthDay();
	std::string GetGroup();
private:
	std::string name;
	std::string birthDay;
	std::string group;
};

