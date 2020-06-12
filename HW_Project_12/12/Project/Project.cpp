#include <iostream>
#include "Array.h"

int main()
{
	Array<int> p;
	p.push_back(30);
	p.push_back(40);
	p.push_back(50);


	Array<int> pro;
	//pro.set_size(3);
	std::cout <<"pro.size() = "<< pro.size() << std::endl;
	pro.push_back(10);
	pro.push_back(15);
	pro.push_back(23);

	for (size_t i = 0; i < pro.size(); i++)
	{
		std::cout << pro[i] << std::endl;
	}
	pro.set_grow(20);
//	pro.set_size(5);
	std::cout << "pro.is_empty() = " << pro.is_empty() << std::endl;
//	pro.append(p);
	pro = p;
	for (size_t i = 0; i < pro.size(); i++)
	{
		std::cout << pro[i] << std::endl;
	}

	std::cout << "pro.get_data() = " << pro.get_data() << std::endl;
	pro.insert_at(1, 10);
	pro.remove_at(0);
	for (size_t i = 0; i < pro.size(); i++)
	{
		std::cout << pro[i] << std::endl;
	}

	pro.push_back(5);
	pro.push_back(3);
	pro.push_back(1);

	pro.sort();
	std::cout << "pro.sort() = "<<std::endl;
	for (size_t i = 0; i < pro.size(); i++)
	{
		std::cout << pro[i] << std::endl;
	}



	pro.remove_all();
	std::cout << "pro.is_empty() = " << pro.is_empty() << std::endl;


}

