#include <iostream>
#include "String.h"

//Семантика перемещения
//move 

int main()
{
	String str_a = "string test";
	String str_b = str_a;
	//std::cout << "\n\n\n";

	std::cout << "\n_________________________\n";
	str_a.print_string();
	std::cout << "\n_________________________\n";

	str_a += str_b;

	str_a.print_string();
	std::cout << "\n_________________________\n";

	return 0;
}

