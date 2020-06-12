#include "Worker.h"
double Worker::s_minimal = 10000;
double Worker::s_tax = 15;
int Worker::length = 12;
int Worker::col = 2;

double** Worker::yearInfo = new double* [length];



Worker::Worker()
{
	for (int i = 0; i < length; i++)
		yearInfo[i] = new double[2];
}


Worker::~Worker()
{
}

std::string Worker::getName()
{
	return w_name;
}

void Worker::setName(std::string value)
{
	w_name = value;
}

double Worker::getOklad()
{
	return s_oklad;
}

void Worker::setOklad(double value)
{
	s_oklad = value;
}

double Worker::getMinimal()
{
	return s_minimal;
}

void Worker::setMinimal(double value)
{
	s_minimal = value;
}

double Worker::getTax()
{
	return s_tax;
}

void Worker::setTax(double value)
{
	s_tax = value;
}

double Worker::get_salary()
{
	return s_minimal * s_oklad;
}

double Worker::get_result_salary()
{
	return (s_minimal * s_oklad) * (1 - (s_tax / 100));
}

 int Worker::Length()
{
	return length;
}

void Worker::setTaxStatic(double value)
{
	s_tax = value;
}

double** Worker::YearInfo()
{
	
	return yearInfo;
}

void Worker::showAnnualReport()
{
	system("cls");
	std::cout << "Month\t\tMinimal\tTax\n" <<
		"January\t\t" << Worker::YearInfo()[0][0] << "\t" << Worker::YearInfo()[0][1] << std::endl <<
		"February\t" << Worker::YearInfo()[1][0] << "\t" << Worker::YearInfo()[1][1] << std::endl <<
		"March\t\t" << Worker::YearInfo()[2][0] << "\t" << Worker::YearInfo()[2][1] << std::endl <<
		"April\t\t" << Worker::YearInfo()[3][0] << "\t" << Worker::YearInfo()[3][1] << std::endl <<
		"May\t\t" << Worker::YearInfo()[4][0] << "\t" << Worker::YearInfo()[4][1] << std::endl <<
		"June\t\t" << Worker::YearInfo()[5][0] << "\t" << Worker::YearInfo()[5][1] << std::endl <<
		"July\t\t" << Worker::YearInfo()[6][0] << "\t" << Worker::YearInfo()[6][1] << std::endl <<
		"August\t\t" << Worker::YearInfo()[7][0] << "\t" << Worker::YearInfo()[7][1] << std::endl <<
		"September\t" << Worker::YearInfo()[8][0] << "\t" << Worker::YearInfo()[8][1] << std::endl <<
		"October\t\t" << Worker::YearInfo()[9][0] << "\t" << Worker::YearInfo()[9][1] << std::endl <<
		"November\t" << Worker::YearInfo()[10][0] << "\t" << Worker::YearInfo()[10][1] << std::endl <<
		"December\t" << Worker::YearInfo()[11][0] << "\t" << Worker::YearInfo()[11][1] << std::endl;
	std::cout << "\npress any button to continue\n";
	system("pause");
}

void Worker::salaryYearInfo(int l, double** yearInfo, int tmp_c, int i)
{
	for (i; i < l; i++)
	{
		if (tmp_c == 1)
			yearInfo[i][0] = Worker::getMinimal();
		else if (tmp_c == 2)
			yearInfo[i][1] = Worker::getTax();

	}
}
