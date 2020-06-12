#include <iostream>
#include <sstream>
#include "Array.h"
#include "Stack.h"

void check_true(bool v) {
	if (v) {
		std::cout << "OK" << std::endl;
	}
	else {
		std::cout << "FAIL" << std::endl;
	}
}

void test_int_array() {
	Array<int> arr1;

	check_true(arr1.is_empty());
	check_true(arr1.size() == 0);
	check_true(arr1.capacity() == 0);

	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);

	check_true(arr1.size() == 4);
	check_true(arr1.capacity() == 10);

	Array<int> arr2 {5,6,7,8};

	Array<int> arr3{ 10,11 };
	/*arr2.push_back(5);
	arr2.push_back(6);
	arr2.push_back(7);
	arr2.push_back(8);*/

	arr1.append(arr2);

	check_true(arr1[0] == 1);
	check_true(arr1[1] == 2);
	check_true(arr1[2] == 3);
	check_true(arr1[3] == 4);
	check_true(arr1[4] == 5);
	check_true(arr1[5] == 6);
	check_true(arr1[6] == 7);
	check_true(arr1[7] == 8);

	arr1.remove_all();
	check_true(arr1.size() == 0);
	check_true(arr1.capacity() == 0);

	arr1 = arr2;
	check_true(arr1.size() == 4);
	check_true(arr1.capacity() == 10);
	arr1[1] = 1;
	check_true(arr1[0] == 5);
	check_true(arr1[1] == 1);
	check_true(arr1[2] == 7);
	check_true(arr1[3] == 8);

	arr1.insert_at(1, 9);
	check_true(arr1[4] == 8);
	check_true(arr1.size() == 5);

	arr1.remove_at(1);
	check_true(arr1.size() == 4);
	check_true(arr1[1] == 1);

	std::stringstream s2;
	s2 << arr1;
	check_true(s2.str() == std::string("5 1 7 8 "));
}

void test_char_array() {
	Array<char> arr1;
	arr1.push_back('H');
	arr1.push_back('e');
	arr1.push_back('l');
	arr1.push_back('l');
	arr1.push_back('o');
	arr1.push_back('\n');

	std::cout << arr1;
	std::stringstream s2;
	s2 << arr1;
	check_true(s2.str() == std::string("Hello\n"));
}

int main()
{
	//test_int_array();
	//test_char_array();
	Stack<int> stack{5,6,7,8};
	/*stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);*/

	std::cout << stack.pop();
	std::cout << stack.pop();
	std::cout << stack.pop();
	std::cout << stack.pop();


	std::cout << "_________________\n\n";
	

	Worker jo; //Worker 1
	std::string temp = "Jon";
	jo.Name(temp);
	temp = "middle";
	jo.Position(temp);
	int k = 27;
	jo.Age(k);
	

	Worker jo2; //Worker 2
	std::string temp2 = "Tom";
	jo2.Name(temp2);
	temp2 = "Junior";
	jo2.Position(temp2);
	int k2 = 28;
	jo2.Age(k2);



	Array<Worker> po; //Array
	po.push_back(jo);
	po.push_back(jo2);

    std::cout << po << std::endl;
	

	return 0;
}
