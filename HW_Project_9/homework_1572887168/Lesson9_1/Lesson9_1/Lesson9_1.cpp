#include <iostream> 
#include <sstream>
#include "Array.h"

void check_true(bool v) {
	if (v) {
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "FAIL" << std::endl;
	}
}

bool compare(double a, double b) {
	return (fabs(a - b) < DBL_EPSILON);
}

int main() {
	Array arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	check_true(arr[0] == 1);
	check_true(arr[1] == 2);
	check_true(arr[2] == 3);
	check_true(arr[3] == 4);

	check_true(arr.size() == 4);
	check_true(arr.capacity() == 10);

	arr[0] = 10;
	arr.operator[](1) = 20;
	arr[2] = 30;
	arr[3] = 40;

	check_true(arr[0] == 10);
	check_true(arr[1] == 20);
	check_true(arr[2] == 30);
	check_true(arr[3] == 40);

	arr(6);
	check_true(arr[0] == 16);
	check_true(arr[1] == 26);
	check_true(arr[2] == 36);
	check_true(arr[3] == 46);


	std::stringstream ss;
	ss << arr;
	check_true(ss.str() == std::string("16 26 36 46 "));
}