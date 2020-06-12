#include <iostream>
#include "Student.h"
int main()
{
	printf("Enter Student quantity: ");
	int SIZE = 5;
	std::cin >> SIZE;

	Student *arr = new Student [SIZE];
	std::string temp_name;

	for (int i = 0; i < SIZE; i++)
	{
		printf("Enter Student's name: ");
		std::cin >> temp_name;
		arr[i].SetName(temp_name);
		printf("Enter Student's birth day: ");
		std::cin >> temp_name;
		arr[i].SetBirthDay(temp_name);
		printf("Enter Student's group: ");
		std::cin >> temp_name;
		arr[i].SetGroup(temp_name);
	}

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "\nstudent's name: " << arr[i].GetName() << std::endl;
		std::cout << "student's birth day: " << arr[i].GetBirthDay() << std::endl;
		std::cout << "student's group: " << arr[i].GetGroup() << std::endl;
	}

}




