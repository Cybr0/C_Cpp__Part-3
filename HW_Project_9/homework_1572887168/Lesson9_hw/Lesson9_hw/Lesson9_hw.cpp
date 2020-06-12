#include <iostream>
#include "String.h"

void check_true(bool v) {
	if (v) {
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "FAIL" << std::endl;
	}
}

int main()
{
	String str("Hello World!");
	str[1] = 'a';
	check_true(str == "Hallo World!");
	return 0;
}

