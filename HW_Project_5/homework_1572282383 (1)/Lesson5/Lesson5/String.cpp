#include "String.h"
#include <string.h>

String::String() : String(80)
{
	
}

String::String(size_t lenght)
{
	data_length = lenght;
	data = new char[data_length];
}

String::String(const char* value)
{
	setString(value);
}

String::String(String& val)
{
	setString(val.getData());
	/*data_length = strlen(val.getData()) + 1;
	if (this->data) {
		delete[](this->data);
	}
	this->data = new char[data_length];
	strcpy_s(this->data, data_length, val.getData());*/
}

String::~String()
{
	delete[] data;
}

void String::setString(const char* data)
{
	data_length = strlen(data) + 1;
	if (this->data) {
		delete[](this->data);
	}
	this->data = new char[data_length];
	strcpy_s(this->data, data_length, data);
}

String& String::addString(const char* value)
{
	size_t old_data_length = strlen(data);
	size_t new_data_length = strlen(value);
	
	data_length = old_data_length + new_data_length + 1;

	char* temp = new char[data_length];
	strcpy_s(temp, old_data_length+1, data);
	strcpy_s((temp + old_data_length), new_data_length + 1, value);
	delete[]data;
	data = temp;
	return *this;
}

const char* String::getData()
{

	return data;
}
