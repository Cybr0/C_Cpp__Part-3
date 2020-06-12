#include "String.h"

int String::quantity = 0;

String::String()
{
	this->size = 80;
	string = new char[size];
	QuantityForConstructor_And_ID();
}

String::String(int size)//:
	//String::String()
{
	this->size = size;
	string = new char[size];
	QuantityForConstructor_And_ID();
}

String::String(const char* string)
{
	SetString(string);
	QuantityForConstructor_And_ID();
}

String::~String()
{
	delete[] string;
}

char* String::GetString()
{
	return string;
}

void String::SetString(const char* string)
{
	if (this->string != nullptr)
		delete[] this->string;
	size = strlen(string) + 1;
	this->string = new char[size];
	strcpy_s(this->string, size, string);

}

int String::Quantity()
{
	return quantity;
}

int String::GetID()
{
	return id;
}

void String::QuantityForConstructor_And_ID()
{
	quantity++;
	id = quantity;
}
