#pragma once
#include <iostream> 
class Array
{
public:
	Array();
	~Array();
	int size() const;
	int capacity() const;
	void push_back(int value);
	//int operator[](int i) const;
	int& operator[](int i);
	Array& operator()(int i, int val);
	void operator()(int value);
	friend std::ostream& operator<<(std::ostream& out, const Array& obj);
private:
	int _size, _capacity;
	const int limit = 10;
	int* array;
};

