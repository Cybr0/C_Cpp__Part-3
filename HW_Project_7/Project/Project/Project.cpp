#include <iostream>
#include "valuta.h"
using namespace std;
int main()
{
	valuta val;
	valuta vv;
	valuta t;

	val = 10;
	val._type(2);
	vv = 20;
	t._type(2);
	t = val + vv;
	bool vot = val == vv;
	cout << "bool = " << vot << endl;
	cout  << "t = "<< t._value() << endl;

	//все работает, но когда цифры большие и надо конвектировать, то тогда double показывает типа 2.8398e+06 long double


}
