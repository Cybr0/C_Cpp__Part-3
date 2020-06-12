#pragma once
#include <iostream>
template <class T>
class Array
{
public:
	Array();
	Array(const std::initializer_list<T> &list);
	~Array();
	int size() const;
	int capacity() const;
	bool is_empty();
	void append(Array<T> other);
	void remove_all();
	void insert_at(int index, int value);
	void remove_at(int index);
	void push_back(T);
	template<char>
	void push_back(char);

	Array<T>& operator=(Array<T>& other);
	T& operator[](int i);
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, Array<U>& data);
	template <char>
	friend std::ostream& operator<<(std::ostream& out, Array<char>& data);
		
private:
	int _size, _capacity;
	const int limit = 10;
	T* array;
};

template <class T>
std::ostream& operator<<(std::ostream& out, Array<T> & data) {
	for (int i = 0; i < data.size(); i++) {
		out << data[i] << " ";
	}
	return out;
}

template <>
std::ostream& operator<<(std::ostream& out, Array<char>& data) {
	out << data.array;
	return out;
}

template <class T>
Array<T>::Array()
{
	_size = 0;
	_capacity = 0;
	array = new T[_capacity];
}

template<class T>
inline Array<T>::Array(const std::initializer_list<T>& list)
{
	for (T item : list) {
		push_back(item);
	}
}

template <class T>
Array<T>::~Array()
{
}

template <class T>
int Array<T>::size() const
{
	return _size;
}

template <class T>
int Array<T>::capacity() const
{
	return _capacity;
}

template <class T>
void Array<T>::push_back(T value)
{
	if (_size < _capacity) {
		array[_size] = value;
	}
	else {
		_capacity += limit;
		T* new_array = new T[_capacity];
		for (int i = 0; i < _size; i++) {
			new_array[i] = array[i];
		}

		new_array[_size] = value;

		delete[] array;
		array = new_array;
	}
	_size++;
}

template<>
inline void Array<char>::push_back(char value)
{
	if (_size+1 < _capacity) {
		array[_size] = value;
		array[_size+1] = '\0';
	} else {
		_capacity += limit;
		char* new_array = new char[_capacity];
		for (int i = 0; i < _size; i++) {
			new_array[i] = array[i];
		}

		new_array[_size] = value;
		new_array[_size + 1] = '\0';
		delete[] array;
		array = new_array;
	}
	_size++;
}

template<class T>
inline bool Array<T>::is_empty()
{
	if (_size == 0)
		return true;
	else
		return false;
}

template<class T>
inline void Array<T>::append(Array<T> other)
{
	for (int i = 0; i < other.size(); i++)
	{
		push_back(other.array[i]);
	}
}

template<class T>
inline void Array<T>::remove_all()
{
	delete[] array;
	_size = 0;
	_capacity = 0;
}

template<class T>
inline void Array<T>::insert_at(int index, int value)
{
	
	if ((_size + 1) >= _capacity)
		_capacity += limit;
		
	T* new_array = new T[_capacity];
	int k = 0;
	for (int i = 0; i < (_size + 1); i++) {

		if (i == index)
		{
			new_array[i] = value;
		}
		else
		{
			new_array[i] = array[k];
			k++;
		}
		
	}
	delete[] array;
	_size++;
	array = new_array;
}

template<class T>
inline void Array<T>::remove_at(int index)
{
	if ((_size - 1) < _capacity)
		_capacity -= limit;

	T * new_array = new T[_capacity];
	int k = 0;
	for (int i = 0; i < (_size - 1); i++) {

		if (i == index)
		{
			k++;
		}
		new_array[i] = array[k];
		k++;
	}
	delete[] array;
	_size--;
	array = new_array;
}

template<class T>
inline Array<T>& Array<T>::operator=(Array<T>& other)
{
	_size = other._size;
	_capacity = other._capacity;
	array = new T[_size];
	for (int i = 0; i < _size; i++)
	{
		array[i] = other.array[i];
	}
	return *this;
}

template <class T>
T& Array<T>::operator[](int i)
{
	try
	{
		if (i < 0 || i >= _size) {
			const char* msg = "\nError: T& Array<T>::operator[](int i).\n";
			throw msg;
		}
	}
	catch (const char* msg)
	{
		std::cout << msg;
	}

	if (i >= _size)  return array[_size - 1];
	return array[i];
}




