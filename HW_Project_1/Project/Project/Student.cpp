#include "Student.h"

void Student::SetName(std::string name)
{
	this->name = name;
}

void Student::SetBirthDay(std::string birthDay)
{
	this->birthDay = birthDay;
}

void Student::SetGroup(std::string group)
{
	this->group = group;
}

std::string Student::GetName()
{
	return name;
}

std::string Student::GetBirthDay()
{
	return birthDay;
}

std::string Student::GetGroup()
{
	return group;
}
