#include <iostream>
#include <queue>
#include <deque>

int main()
{
	std::deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);

	for (int item : dq) {
		std::cout << item;
	}
	std::cout << std::endl;
	/*dq.clear();
	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	for (int item : dq) {
		std::cout << item;
	}*/
}
