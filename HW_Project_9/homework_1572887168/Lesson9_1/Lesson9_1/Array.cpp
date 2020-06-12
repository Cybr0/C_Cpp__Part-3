#include "Array.h"
#include <iostream>

Array::Array()
{
	_size = 0;
	_capacity = limit;
	array = new int[_capacity];
}

Array::~Array()
{
}

int Array::size() const
{
	return _size;
}

int Array::capacity() const 
{
	return _capacity;
}

void Array::push_back(int value)
{
	if (_size < _capacity) {
		array[_size] = value;
		
	} else {
		_capacity += limit;
		int* new_array = new int[_capacity];
		for (int i = 0; i < _size; i++) {
			new_array[i] = array[i];
		}
		
		new_array[_size]=value;

		delete[] array;
		array = new_array;
	}
	_size++;
}

//int Array::operator[](int i) const
//{
//	if (i >= _size) {
//		return array[_size - 1];
//	}
//	return array[i];
//}
//
int& Array::operator[](int i)
{
	if (i >= _size) {
		return array[_size - 1];
	}
	return array[i];
}

Array& Array::operator()(int i, int val)
{
	operator[](i) = val;
	return *this;
}

void Array::operator()(int value)
{
	for (int i = 0; i < _size; i++) {
		array[i] += value;
	}
}

std::ostream& operator<<(std::ostream& out, const Array& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		out << obj.array[i] << " ";
	}
	
	return out;
}
