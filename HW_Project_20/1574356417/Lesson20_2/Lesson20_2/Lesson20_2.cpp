#include <iostream>
#include "Stack.h"
#include "Vector.h"
int main()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	Stack<int> ss = st;
	while (ss.size() > 0) {
		std::cout << ss.pop();
	}
	Vector<int> vv;
	vv.get(10);
}
