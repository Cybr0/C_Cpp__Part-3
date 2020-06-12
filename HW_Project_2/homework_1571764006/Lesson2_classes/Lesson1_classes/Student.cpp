#include "Student.h"
#include <iostream>

Student::Student():
	name{ "No name" },
	birthDate{ "10.10.2047" },
	group{ "No group" },
	value{0}
{
	//name = "No name";
	//birthDate = "10.10.2047";
	//group = "No group";
	//value = 0;
	address = new char[20];
	std::cout << "Constructor!\n";
}

Student::Student(std::string n) :
	name(n),
	birthDate("10.10.2047"),
	group("No group"),
	value(0)
{
	address = new char[20];
}

Student::Student(std::string n, std::string d):
	Student()
{
	name = n;
	birthDate = d;
}

Student::~Student()
{
	delete[]address;
	std::cout << "Destructor!\n";
}

//void student::name(std::string v) {
//	name = v;
//}


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
