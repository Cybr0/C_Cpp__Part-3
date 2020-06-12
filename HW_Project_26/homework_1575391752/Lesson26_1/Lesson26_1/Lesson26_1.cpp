#include <iostream>
#include <typeinfo>
#include <string>
#include <typeindex>

template<typename T>
T sum(T a, T b) {
	if (typeid(double).hash_code() == typeid(T).hash_code()) {
		std::cout << "double\n";
	}
	return a + b;
}

class A {
public:
	virtual void print() {
		std::cout << "print A\n";
	}
};

class B : public A{
public:
	virtual void print() override {
		std::cout << "print B\n";
	}
};

int main()
{
/*	int i;
	double d = 3.14;
	char c = 'a';
	std::string s;
	
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(s).name() << std::endl;

	const std::type_info& inf1 = typeid(i);
	const std::type_info& inf2 = typeid(i);

	if (&inf1 == &inf2) {
		//равенство НЕ гарантируется 
	}
	if (inf1.hash_code() == inf2.hash_code()) {
		//гарантируется равенство
	}
	if (std::type_index(inf1) == std::type_index(inf2)) {
		//гарантируется равенство
	}
	*/
/*	std::cout << sum(int(2), int(3)) << std::endl;
	std::cout << sum(double (2), double(3)) << std::endl;
	*/

	A* a_obj = new A();
	A* b_obj = new B();

	std::cout << typeid(*a_obj).name() << std::endl;
	std::cout << typeid(*b_obj).name() << std::endl;
}
