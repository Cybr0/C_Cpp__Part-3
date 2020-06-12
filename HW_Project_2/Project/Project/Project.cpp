#include <iostream>
#include "String.h"

int main()
{
	String first_1;
	first_1.SetString("hi,");
	String first_2("Yusupov");
	String first_3(10);
	first_3.SetString("Timur!");

	std::cout << "Quantity of objects: " << first_1.Quantity() << std::endl << std::endl;
	std::cout << "ID: "<< first_1.GetID() << "\tfirst_1 = " << first_1.GetString() << std::endl;
	std::cout << "ID: " << first_2.GetID() << "\tfirst_2 = " << first_2.GetString() << std::endl;
	std::cout << "ID: " << first_3.GetID() << "\tfirst_3 = " << first_3.GetString() << std::endl;
}

