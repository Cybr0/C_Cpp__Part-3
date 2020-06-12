#include <iostream>
#include <string>

class MyClass {
public:
	int value;
	void print() {
		std::cout << "in_obj1::name:" << in_obj1.name << std::endl;
		std::cout << "in_obj2::name:" << in_obj2.name << std::endl;
	}

	class InnerClas1 {
	public:
		InnerClas1() { 	name = "inner class 1"; }
		std::string name;
	};

	InnerClas1 in_obj1;
private:
	class InnerClas2 {
	public:
		InnerClas2() { name = "inner class 2";}
		std::string name;
	};
public:
	InnerClas2 in_obj2;
	int prv_val;
};

int main()
{
	MyClass my_obj;
	MyClass::InnerClas1 in_obcl;
	MyClass::InnerClas2 in_obcl2;
}
