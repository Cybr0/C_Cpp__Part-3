#include <iostream>
#include "Worker.h"

int main()
{
	const size_t size = 3;
	Worker w_array[size];
	std::string temp;
	double tmp_oklad;
	for (size_t i = 0; i < size; i++) {
		std::cout << "Name:";
		std::cin >> temp;
		w_array[i].setName(temp);
		std::cout << "Oklad:";
		std::cin >> tmp_oklad;
		w_array[i].setOklad(tmp_oklad);
	}

	while (true) {

		for (size_t i = 0; i < size; i++) {
			std::cout << w_array[i].getName() << " "
				<< w_array[i].get_salary() << " "
				<< w_array[i].get_result_salary() << std::endl;
		}

		std::cout << "1. edit minimal;\n"
			<< "2. edit tax;\n"
			<< "3. exit;\n";
		int tmp_c;
		std::cin >> tmp_c;
		switch (tmp_c) {
		case 1: {
			double v;
			std::cin >> v;
			Worker::s_minimal = v;
			/*for (size_t i = 0; i < size; i++) {
				w_array[i].setMinimal(v);
			}*/
		}
			break;
		case 2:
			double v;
			std::cin >> v;
			Worker::setTaxStatic(v);
			//w_array[0].setTax(v);
			/*for (size_t i = 0; i < size; i++) {
				w_array[i].setTax(v);
			}*/
			break;
		case 3:
			return 0;
		}
	}
	return 0;
}
