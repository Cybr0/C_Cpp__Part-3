#include <iostream>
#include <string>
#include <vector>
class goods {
public:
	goods() {
		std::cout << "goods()" << std::endl;
	}
	~goods() {
		std::cout << "~goods()" << std::endl;
	}
	std::string model;
	double price;
	double power;
	int available_count;
	int color;
	int barcode[16];
};

class tv:public goods {
public:
	tv() {
		std::cout << "tv()" << std::endl;
	}
	~tv() {
		std::cout << "~tv()" << std::endl;
	}
	
	double diagonale;
	std::vector<int> format_list;
};

class oven : public goods {
public:
	oven() {
		std::cout << "oven()" << std::endl;
	}
	~oven() {
		std::cout << "~oven()" << std::endl;
	}
	double volume;
	std::vector<int> mode_list;
};

class grinder: virtual public goods {
public:
	grinder() {
		std::cout << "grinder()" << std::endl;
	}
	~grinder() {
		std::cout << "~grinder()" << std::endl;
	}
	std::vector<int> blides;
	std::vector<int> grind_modes;
};

class mixer: virtual public goods {
public:
	mixer() {
		std::cout << "mixer()" << std::endl;
	}
	~mixer() {
		std::cout << "~mixer()" << std::endl;
	}
	int tool_count;
	std::vector<int> mix_modes;
};

class combine : public mixer, public grinder {
public:
	combine() {
		std::cout << "combine()" << std::endl;
	}
	~combine() {
		std::cout << "~combine()" << std::endl;
	}
};

int main()
{
	tv tv_item;
	oven oven_item;
	oven_item.price = 2.23;
	mixer mx;
	mx.price = 23.33;

	combine comb_item;
	comb_item.price = 0.01;
	comb_item.power = 12;
}
