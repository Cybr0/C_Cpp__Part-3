#pragma once
#include "Worker.h"

class Organization
{
public:
	Organization();
	~Organization();
	void doWorker();
	void deleteWorker(int index);
	void showTable();
	void showAnnualReportOfWorkers();
	void changeWorkerInfo(int index);
	Worker* getWorkers();
	int getSize();


private:
	Worker* workers;
	int size;
};

