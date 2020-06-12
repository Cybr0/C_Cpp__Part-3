#include <iostream>
#include <string>
#include "Array.h"

double devide1(double a, double b) {
	if (b == 0) {
		std::cout << "devision by zero...";
		return 0;
	}
	return a / b;
}
double devide2(double a, double b, bool &ok) {
	if (b == 0) {
		ok = false;
		return 0;
	}
	ok = true;
	return a / b;
}
struct error_code_struct {
	enum error_codes {
		er_ok = 0,
		er_not_available = 1,
		er_server_error = 503
	};
	error_codes code;
	std::string text;
};
double func(error_code_struct & erc) {
	erc.code = error_code_struct::er_ok;
	erc.text = "OK";

	erc.code = error_code_struct::er_not_available;
	erc.text = "OK";
	return 0;
}

double devide3(double a, double b) {
	error_code_struct err;
	err.text = "some error";
	std::cout << "action1\n";
	if (b == 0) {
		throw err;
	}
	std::cout << "action2\n";
	return 0;
}

void some_func() {
	try {
		devide3(1, 0);
	}
	catch (error_code_struct & erc) {
		std::cout << "error_code_struct:" << erc.text << std::endl;
		throw "qwqw";
	}
	catch (const char* msg) {
		std::cout << "const char*:" << msg<<std::endl;
		
	}
}

int main()
{
	try {
		Array<int> arr;
		arr[2] = 4;
	}
	catch (const char*msg) {
		std::cout << "msg:"<<msg<<std::endl;
	}
	catch (...) {
		std::cout << "Unknown error";
	}
}
