#include <iostream>
#include "Student.h"

int main()
{
	Student stObject;
	
	stObject.Name("My name");
	
	std::cout << "Name:" << stObject.Name() << std::endl;
	/*std::cout << "date:" << stObject.birthDate << std::endl;
	std::cout << "group:" << stObject.group << std::endl;*/

}
