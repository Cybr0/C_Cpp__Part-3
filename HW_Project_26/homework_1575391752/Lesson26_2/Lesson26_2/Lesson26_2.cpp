#include <iostream>
class A {
public:
	virtual void print() {
		std::cout << "class A\n";
	}
};
class C {
public:
	void print() {
		std::cout << "class C\n";
	}
};
class B:public A {
public:
	virtual void print()override {
		std::cout << "class B\n";
	}
};

int main()
{
	double d = 3.14;
	int e = (int)d;//В стиле С
	int f = int(d);//В стиле С++
	int g = static_cast<int>(d);//C++
	B* b_obj = new B();
	A* a_obj = static_cast<A*>(b_obj);

	//const_cast
	const int* size = new int(30);
	
	int* m_size = const_cast<int*>(size);
	*m_size = 10;
	std::cout << *size;

	//reinterpret_cast
	int a;
	const char* str = "Hello world!";
	std::cout << std::endl;

	a = reinterpret_cast<int>(str);
	std::cout << a;
	std::cout << std::endl;
	char* str2 = reinterpret_cast<char*>(a);
	std::cout << str2;

	std::cout << std::endl;
	//dynamic_cast
	B* b_obj_c = new B();
	A* tmp = dynamic_cast<A*>(b_obj_c);
	if (tmp) {
		std::cout << "<A*>(b_obj_c):OK";
	}
	std::cout << std::endl;
	C* c_obj_c = new C();
	A* tmp1 = (A*)(c_obj_c);//ошибка
	if (tmp1) {
		std::cout << "<A*>(c_obj_c):OK";
	}
	else {
		std::cout << "<A*>(c_obj_c):FAIL";
	}
	std::cout << std::endl;
	A* a_obj2 = new A();
	B* b_obj2 = dynamic_cast<B*>(a_obj2);
	if (b_obj2) {
		std::cout << "<B*>(a_obj2):OK";
	}
	else {
		std::cout << "<B*>(a_obj2):FAIL";
	}
}

