#include <iostream>
#include <queue>
#include <deque>
#include "Deque.h"
#include <initializer_list>
#include <list>
#include <vector>

template<typename T>
void print(Deque<T>& dq) {
	for (size_t i = 0; i < dq.size(); i++)
	{
		std::cout << dq[i];
	}
	std::cout << "\n";
}

int main()
{
	Deque<int> dq_1{1,2,3};
	//dq_1.clear();
	dq_1.push_front(1);
	dq_1.push_front(2);
	dq_1.push_front(3);


	std::cout << "\ndq_1 =\t";
	print(dq_1);


	Deque<int> dq_2;
	dq_2 = dq_1;

	std::cout << "\n\ndq_2 =\t";
	print(dq_2);
	std::cout << "\n";
}
