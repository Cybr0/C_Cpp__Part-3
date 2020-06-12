#include "Student.h"
Student::Student()
{
}

Student::~Student()
{
}

void Student::Name(std::string v) {
	name = v;
}

std::string Student::Name()
{
	return name;
}

void Student::Date(std::string val)
{
	birthDate = val;
}

std::string Student::Date()
{
	return birthDate;
}

void Student::Group(std::string val)
{
	group = val;
}

std::string Student::Group()
{
	return group;
}
