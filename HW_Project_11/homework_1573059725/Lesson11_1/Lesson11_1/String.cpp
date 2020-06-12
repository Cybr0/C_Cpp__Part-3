#include "String.h"
//#include <iostream>
#include <string.h>

String::String()
{
	//std::cout << "String()\n";
	value = nullptr;
	val_size = 0;
}

String::String(const char*v)
{
	//std::cout << "String(const char*v)\n";
	value = nullptr;
	set_data(v);
}

String::String(String& obj)
{
	//std::cout << "String(String& obj)\n";
	value = nullptr;
	set_data(obj.data());
}

String::String(String&& obj)
{
	//std::cout << "String(String&& obj)\n";
	value = obj.value;
	val_size = obj.val_size;
	obj.value = nullptr;
	obj.val_size = 0;
}

String::~String()
{
	//std::cout << "~String()\n";
	if (value) {
		delete[] value;
	}
}

void String::set_data(const char* v)
{
	if (value) {
		delete[] value;
	}
	val_size = strlen(v) + 1;
	value = new char[val_size];
	strcpy_s(value, val_size, v);
}

void String::add_data(const char* v)
{
	size_t old_data_length = strlen(value);
	size_t new_data_length = strlen(v);

	val_size = old_data_length + new_data_length + 1;

	char* temp = new char[val_size];
	strcpy_s(temp, old_data_length + 1, value);
	strcpy_s((temp + old_data_length), new_data_length + 1, v);
	delete[]value;
	value = temp;
}

const char* String::data()
{
	return value;
}

size_t String::size()
{
	return val_size;
}

String& String::operator+=(String& value)
{
		this->add_data(value.value);
		return *this;
}

bool String::is_gen(const char* first, const char* second)
{
	int size_a = sizeof(first);
	int size_b = sizeof(second);
	int min;
	bool ret_val;
	if (size_a < size_b) {
		min = size_a;
		ret_val = true;
	}
	else {
		min = size_b;
		ret_val = false;
	}
	for (int i = 0; i < min - 1; i++) {
		if (tolower(first[i]) > tolower(second[i])) { // Check with tolower allow all register issue
			return true;
		}
		else if (tolower(first[i]) < tolower(second[i])) { // Check with tolower allow all register issue
			return false;
		}
	}
	return ret_val;
}



void String::print_string()
{
	for (size_t i = 0; i < val_size; i++)
	{
		std::cout << value[i];
	}
}
