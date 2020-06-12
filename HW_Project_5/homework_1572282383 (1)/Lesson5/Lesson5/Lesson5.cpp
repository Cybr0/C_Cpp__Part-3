#include <iostream>
#include "String.h"

int main()
{
	String str1("Hello world!");
	std::cout << str1.getData() << std::endl;

	String str2(str1);
	str2.setString("New string");
	std::cout << str1.getData() << std::endl;
}
