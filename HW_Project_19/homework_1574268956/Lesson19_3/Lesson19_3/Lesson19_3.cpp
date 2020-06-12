#include <iostream>
class Animal {
public:
	Animal() {
		std::cout << "Animal()\n";
	}
	~Animal() {
		std::cout << "~Animal()\n";
	}
	int age;
	int weight;
	
protected:
	int type;
	int get_color() {
		return color;
	}
private:
	int color;
	
};
class Mammal :public Animal {
public:
	Mammal() {
		std::cout << "Mammal()\n";
	}
	~Mammal() {
		std::cout << "~Mammal()\n";
	}
	int teth_count;
	void show_info() {
		std::cout << "age:" << age << std::endl
			<< "weight:" << weight << std::endl
			<< "type:" << type << std::endl
			<< "color:" << get_color() << std::endl;
	}
	void sound() {
		std::cout << "Voice\n";
	}
};

class Cat : public Mammal {
public:
	Cat() {
		std::cout << "Cat()\n";
	}
	~Cat() {
		std::cout << "~Cat()\n";
	}
	void sound() {
		std::cout << "Meow\n";
	}
};

int main()
{
	Cat* m_cat = new Cat();
	m_cat->sound();
	delete m_cat;
}
