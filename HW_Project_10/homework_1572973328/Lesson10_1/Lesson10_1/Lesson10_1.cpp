#include <iostream>
#include <sstream>
#include "Array.h"
#include "String.h"
#include "Worker.h"

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
	String str;
	str = "test string";
	std::stringstream s1;
	s1 << str;
	check_true(s1.str() == std::string(str.data()));
	
	Array arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	std::stringstream s2;
	s2 << arr;
	check_true(s2.str() == std::string("1 2 3 4 "));

	Worker wrk;
	wrk = "John";
	wrk = int(10);
	wrk = double(100);
	std::stringstream s3;
	s3 << wrk;
	check_true(s3.str() == std::string("name:John\nstage:10\nsalary:100.00"));
}

