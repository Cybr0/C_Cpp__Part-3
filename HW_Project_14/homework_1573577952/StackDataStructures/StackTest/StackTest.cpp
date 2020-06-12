#include <iostream>
#include <stack>
#include "dynamic_array_stack.h"

int main()
{
	/*std::stack<int> v_stack;
	v_stack.push(1);
	v_stack.push(2);
	v_stack.push(3);

	while (!v_stack.empty()) {
		std::cout << v_stack.top() << " ";
		v_stack.pop();
	}*/
	//std::cout << v_stack.top() << " ";

	dynamic_array_stack<int> v_st2(10);
	v_st2.push(1);
	v_st2.push(2);
	v_st2.push(3);

	while (!v_st2.empty()) {
		std::cout << v_st2.top() << " ";
		v_st2.pop();
	}
	std::cout << v_st2.top() << " ";



	////////////////////////////char
	std::cout << "\n\n_______________________________\n\n";



	dynamic_array_stack<char> v_char(10);
	v_char.push('a');
	v_char.push('b');
	v_char.push('c');

	while (!v_char.empty()) {
		std::cout << v_char.top() << " ";
		v_char.pop();
	}
	std::cout << v_char.top() << " ";

	std::cout << "\n\n_______________________________\n\n";
}
