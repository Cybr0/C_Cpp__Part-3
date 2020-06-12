#include <iostream>
#include "Worker.h"

void check_true(bool v) {
	if (v) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "FAIL" << std::endl;
	}
}

bool compare(double a, double b) {
	return (fabs(a - b) < DBL_EPSILON);
}

int main()
{
	Worker w1;
	w1 = "John Doe";
	w1 = double(1000);
	w1 = int(10);

	Worker w2;
	w2 = "Jane Doe";
	w2 = double(800);
	w2 = int(3);

	check_true(w1 != w2);
	check_true(w1 < w2);
	check_true(w2 > w1);

	check_true(w1.name() == "John Doe");
	check_true(w1.salary() == double(1000));
	check_true(w1.stage() == 10);

	check_true(w2.name() == "Jane Doe");
	check_true(w2.salary() == double(800));
	check_true(w2.stage() == 3);


	check_true(std::string(w1) == "John Doe");
	check_true(double(w1) == 1000);
	check_true(int(w1) == 10);

	check_true(static_cast<std::string>(w2) == "Jane Doe");
	check_true(static_cast<double>(w2) == 800);
	check_true(static_cast<int>(w2) == 3);

	int a = w1;
	std::cout << a << std::endl;
}
