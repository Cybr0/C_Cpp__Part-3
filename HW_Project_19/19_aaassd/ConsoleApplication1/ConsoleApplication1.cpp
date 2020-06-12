#include <iostream>
#include "Header.h"

int main()
{
    //std::cout << "Hello World!\n"; 
	Dog maru("Maru",1,10,4);
	maru.voice();

	Dog wolf(maru);
	//wolf.voice();
	std::cout <<"nickname: "<< wolf.Nickname() << " " <<"  age: "<< wolf.Age() << "  weight: " << wolf.Weight() << std::endl;

	Bird kra("Kra", 2, 1, 2);
	std::cout << "\n-----------------------\n";
	kra.voice();
	std::cout <<"nickname: "<< kra.Nickname() << " " << "  age: " << kra.Age() << "  weight: " << kra.Weight() << std::endl;

	Pet neo(kra);
	std::cout << "\n-----------------------\n";
	neo.voice();
	neo.Nickname("Neo");
	neo.Weight(9);
	std::cout << "nickname: " << neo.Nickname() << " " << "  age: " << neo.Age() << "  weight: " << neo.Weight() << std::endl;

}


