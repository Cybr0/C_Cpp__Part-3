#include "valuta.h"

valuta::valuta():
	value{0},
	type {ct_usd}
{
}

valuta::~valuta()
{
}

double valuta::_value()
{
	return value;
}

void valuta::_type(int type)
{
	if (this->type != type) {
		if (type == 1) {
			this->type = 1;
			value /= 9466;
		}
		else {
			this->type = 2;
			value *= 9466;
		}
	}
	
}

void valuta::_check_type(valuta& other)
{
	if (this->type != other.type) {
		if (other.type == 1) {
			other.type = 2;
			other.value *= 9466;
		}
		else {
			other.type = 1;
			other.value /= 9466;
		}
	}
}

double& valuta::operator+(double value)
{
	double temp = value + this->value;
	return temp;
}

valuta& valuta::operator+(valuta& other)
{
	valuta *temp = new valuta;
	_check_type(other);
	temp->type = this->type;
	temp->value = this->value + other.value;
	return *temp;
}

double& valuta::operator-(double value)
{
	double temp = value - this->value;
	return temp;
}

valuta& valuta::operator-(valuta& other)
{
	valuta* temp = new valuta;
	_check_type(other);
	temp->type = this->type;
	temp->value = this->value - other.value;
	return *temp;
}

double& valuta::operator*(double value)
{
	double temp = value * this->value;
	return temp;
}

valuta& valuta::operator*(valuta& other)
{
	valuta* temp = new valuta;
	_check_type(other);
	temp->type = this->type;
	temp->value = this->value * other.value;
	return *temp;
}

double& valuta::operator/(double value)
{
	double temp = value / this->value;
	return temp;
}

valuta& valuta::operator/(valuta& other)
{
	valuta* temp = new valuta;
	_check_type(other);
	temp->type = this->type;
	temp->value = this->value / other.value;
	return *temp;
}

double& valuta::operator=(double value)
{
	this->value = value;
	return this->value;
}

valuta& valuta::operator=(valuta& other)
{
	_check_type(other);
	this->value = other.value;
	return *this;
}

bool valuta::operator==(double value)
{
	return this->value == value;
}

bool valuta::operator==(valuta& other)
{
	return this->value == other.value;
}

bool valuta::operator<(double value)
{
	return this->value < value;
}

bool valuta::operator<(valuta& other)
{
	return this->value < other.value;
}

bool valuta::operator>(double value)
{
	return this->value > value;
}

bool valuta::operator>(valuta& other)
{
	return this->value > other.value;
}

valuta& valuta::operator++()
{
	value++;
	return *this;
}

valuta& valuta::operator++(int opp)
{
	valuta temp = *this;
	this->value++;
	return temp;
}

valuta& valuta::operator--()
{
	value--;
	return *this;
}

valuta& valuta::operator--(int opp)
{
	valuta temp = *this;
	this->value--;
	return temp;
}
