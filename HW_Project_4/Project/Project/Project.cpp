#include <iostream>
#include "Organization.h"
#include "Worker.h"




int chooseMonth() {
	system("cls");
	std::cout<< "Choose month:\n 1.January\n 2.February\n 3.March\n 4.April\n 5.May\n 6.June\n 7.July\n 8.August\n 9.September\n 10.October\n 11.November\n 12.December\n> ";
	int choose_temp;
	std::cin >> choose_temp;
	if (choose_temp < 1 || choose_temp > 12) {
		choose_temp = 1;
	}
	return (choose_temp - 1);
}

int main()
{
	/*const int size = 3;
	Worker w_array[size];
	std::string temp;
	double tmp_oklad;
	std::cout << "Workers:\nSet name and oklad:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "Name:";
		std::cin >> temp;
		w_array[i].setName(temp);
		std::cout << "Oklad:";
		std::cin >> tmp_oklad;
		w_array[i].setOklad(tmp_oklad);
	}*/

	Organization org;
	std::cout << "Workers:\nSet name and oklad:\n";
	org.doWorker();
	org.doWorker();
	org.doWorker();

	
	int temp_for_salaryYearInfo = 0;
	Worker::salaryYearInfo(Worker::Length(), Worker::YearInfo(), 1, temp_for_salaryYearInfo);
	Worker::salaryYearInfo(Worker::Length(), Worker::YearInfo(), 2, temp_for_salaryYearInfo);


	while (true) {
		system("cls");
		for (int i = 0; i < size; i++) {
			std::cout <<"\nName: "<< org.getWorkers()[i].getName() << "\nSalary: "
				<< org.getWorkers()[i].get_salary() << "\nResult_salary: "
				<< org.getWorkers()[i].get_result_salary() << std::endl << std::endl;
		}

		std::cout << "\n1. Edit minimal;\n";;
		std::cout << "2. Edit tax;\n";
			std::cout << "3. Show annual report;\n";
			std::cout << "4. Add worker;\n";
			std::cout << "5. Delete worker;\n";
			std::cout << "6. Show workers table;\n";
			std::cout << "7. Show annual report of workers;\n";
			std::cout << "8. Change worker by id;\n";
			std::cout << "9. Save to file;\n";
			std::cout << "10. Read from file;\n";
			std::cout << "11. Exit;\n";
		int tmp_c;
		std::cin >> tmp_c;
		switch (tmp_c) {
		case 1: {
			temp_for_salaryYearInfo = chooseMonth();
			std::cout << "Set Minimal: ";
			double v;
			std::cin >> v;
			//w_array[0].setMinimal(v);
			org.getWorkers()[0].setMinimal(v);
			Worker::salaryYearInfo(Worker::Length(), Worker::YearInfo(), tmp_c, temp_for_salaryYearInfo);
			
		}
			  break;
		case 2:
			temp_for_salaryYearInfo = chooseMonth();
			

			std::cout << "Set Tax: ";
			double v;
			std::cin >> v;
			Worker::setTaxStatic(v);
			Worker::salaryYearInfo(Worker::Length(), Worker::YearInfo(), tmp_c, temp_for_salaryYearInfo);
			
			break;
		case 3:
			
			Worker::showAnnualReport();
			break;
		case 4:
			org.doWorker();
			break;
		case 5:
			std::cout << "Enter id worker: ";
			int id_temp;
			std::cin >> id_temp;
			org.deleteWorker(id_temp);
			break;
		case 6:
			system("cls");
			org.showTable();
			break;
		case 7:
			system("cls");
			org.showAnnualReportOfWorkers();
			break;
		case 8:
			std::cout << "Enter id worker: ";
			int id_temp;
			std::cin >> id_temp;
			org.changeWorkerInfo(id_temp);
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			return 0;
		default:
			return 0;
		}
	}
	return 0;
}
