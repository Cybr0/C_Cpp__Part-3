#include "Organization.h"

Organization::Organization()
{
	size = 0;
	workers = nullptr;
}


Organization::~Organization()
{
}

Organization* Organization::operator=(Organization* other)
{
	size = other->size;
	if (workers != nullptr)
	{
		delete[] workers;
	}
	workers = other->workers;
	return this;
}

void Organization::doWorker()
{
	Worker* temp = new Worker[(size + 1)];
	for (int i = 0; i < size; i++) {
		if (size != 0) {
			temp[i] = workers[i];
		}
	}

	std::string temp_name;
	double tmp_oklad;
	std::cout << "Name:";
	std::cin >> temp_name;
	temp[size].setName(temp_name);
	std::cout << "Oklad:";
	std::cin >> tmp_oklad;
	temp[size].setOklad(tmp_oklad);

	size++;
	delete[] workers;
	workers = temp;
}

void Organization::deleteWorker(int index)
{
	if (size != 0) {
		Worker* temp = new Worker[(size - 1)];

		int k = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				temp[k] = workers[i];
				k++;
			}

		}
		size--;
		delete[] workers;
		workers = temp;
	}
}

void Organization::showTable()
{
	for (int i = 0; i < size; i++) {
		std::cout << (i + 1) << workers[i].getName() << workers[i].getOklad() << std::endl;
	}
}

void Organization::showAnnualReportOfWorkers()
{
	for (int i = 0; i < size; i++) {
		std::cout << workers[i].getName() << std::endl;
		Worker::showAnnualReport();
	}

}

void Organization::changeWorkerInfo(int index)
{
	std::string temp_name;
	double tmp_oklad;
	std::cout << "Name:";
	std::cin >> temp_name;
	workers[index].setName(temp_name);
	std::cout << "Oklad:";
	std::cin >> tmp_oklad;
	workers[index].setOklad(tmp_oklad);
}

Worker* Organization::getWorkers()
{
	return workers;
}

int Organization::getSize()
{
	return size;
}
