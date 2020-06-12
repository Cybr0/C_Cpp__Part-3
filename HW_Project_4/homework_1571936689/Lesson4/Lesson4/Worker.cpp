#include "Worker.h"

double Worker::s_minimal = 10000;
double Worker::s_tax = 15;

Worker::Worker()
{

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
	return (s_minimal * s_oklad) * ( 1- (s_tax / 100));
}

void Worker::setTaxStatic(double value)
{
	s_tax = value;
}
