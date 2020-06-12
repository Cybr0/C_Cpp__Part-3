#include <iostream>
#include "Student.h"

int main()
{
	//Student stObject{"Def name"};//constructor
	Student stObject("New name");//constructor Student(std::string n);
	//Student stObject("New name", "01.01.2019");//constructor Student(std::string n);
	//stObject.Name("My name");
	//stObject.Date("My name");
	//stObject.Group("My name");
	
	stObject.Address("My address");
	std::cout << "Name:" << stObject.Name() << std::endl;
	std::cout << "date:" << stObject.Date() << std::endl;
	std::cout << "group:" << stObject.Group() << std::endl;
	std::cout << "Value:" << stObject.Val() << std::endl;
	std::cout << "Address:" << stObject.Address() << std::endl;

	Student vals[10];
}
