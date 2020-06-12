#pragma once
template<class T>
class Array
{
public:
	Array();
	~Array();
	int size();
	bool set_size(int size);
	int get_grow();
	void set_grow(int);
	bool is_empty();
	bool remove_all();
	T& operator[](int i);
	void push_back(T );
	T* append(const Array<T>& otherArr);
	T* operator=(const Array<T>& otherArr);
	T* get_data();
	void insert_at(int index, T value);
	void remove_at(int index);
	void sort();
private:
	T* _arr;
	int _size;
	int _max_size;
	int _grow;
};

//#include "Array.h"

template<class T>
inline Array<T>::Array() :
	_grow{ 10 },
	_size{ 0 },
	_max_size{ 0 }
{
	_arr = nullptr;
}

template<class T>
Array<T>::~Array()
{
	if (_size > 0) {
		delete[] _arr;
	}
		
}

template<class T>
int Array<T>::size()
{
	return _size;
}

template<class T>
bool Array<T>::set_size(int size)
{
	if (size >= _max_size) {
		T* new_arr = new T[(size+_grow)];
		for (int i = 0; i < _size; i++)
		{
			new_arr[i] = _arr[i];
		}
		delete[] _arr;
		_arr = new_arr;
		_size = size;
		return true;
	}
	else if (size < _max_size && size > _size)
	{
		_size = size;
		return true;
	}
	return false;
}

template<class T>
int Array<T>::get_grow()
{
	return _grow;
}

template<class T>
void Array<T>::set_grow(int grow)
{
	_grow = grow;
}

template<class T>
bool Array<T>::is_empty()
{
	return (!_arr);

}

template<class T>
bool Array<T>::remove_all()
{
	if (_arr != nullptr) {
		delete[] _arr;
		_size = 0;
		return true;
	}

	return false;
}

template<class T>
T& Array<T>::operator[](int i)
{
	return _arr[i];
}

template<class T>
void Array<T>::push_back(T value)
{
	if (_size >= _max_size) {
		_max_size += _grow;
		T* new_arr = new T[_max_size];
		for (int i = 0; i < _size; i++)
		{
			new_arr[i] = _arr[i];
		}
		new_arr[_size] = value;

		delete[]_arr;
		_arr = new_arr;
	}
	else
	{
		_arr[_size] = value;
	}
	_size++;
}

template<class T>
T* Array<T>::append(const Array<T>& otherArr)
{
	int double_size = (_size + otherArr._size);
	//if (double_size < _max_size) {
	//	for (int i = _size; i < double_size; i++)
	//	{
	//		_arr[i] = otherArr._arr[i];
	//	}
	//}
	//else
	//{
		T* new_arr = new T[(double_size + _grow)];

		for (int i = 0; i < _size; i++)
		{
			new_arr[i] = _arr[i];
		}
		for (int i = _size; i < double_size; i++)
		{
			_arr[i] = otherArr._arr[i];
		}

		delete _arr;
		_arr = new_arr;
//	}
	_size = double_size;
	
	return _arr;
}

template<class T>
T* Array<T>::operator=(const Array<T>& otherArr)
{
	if (otherArr._size <= _max_size)
	{
		for (int i = 0; i < otherArr._size; i++) {
			_arr[i] = otherArr._arr[i];
		}
	}
	else
	{
		T* new_arr = new T[(otherArr._size + _grow)];
		for (int i = 0; i < otherArr._size; i++) {
			new_arr[i] = otherArr._arr[i];
		}
		delete[] _arr;
		_arr = new_arr;
	}
	_size = otherArr._size;
	return _arr;
}

template<class T>
T* Array<T>::get_data()
{
	return _arr;
}

template<class T>
void Array<T>::insert_at(int index, T value)
{

	int temp_size;
	if (_size < _max_size)
	{
		temp_size = _max_size;
	}
	else
	{
		temp_size = _max_size + _grow;
	}

	T* new_arr = new T[temp_size];
	int k = 0;
	for (int i = 0; i < _size + 1; i++) {
		if (i == index) {
			new_arr[i] = value;
		}
		else
		{
			new_arr[i] = _arr[k];
			k++;
		}

	}
	delete[] _arr;
	_arr = new_arr;
	_size++;
}

template<class T>
void Array<T>::remove_at(int index)
{
	T* new_arr = new T[_max_size];
	int k = 0;
	for (int i = 0; i < _size; i++) {
		if (i == index) {
	//		new_arr[k] = _arr[i];
		}
		else
		{
			new_arr[k] = _arr[i];
			k++;
		}

	}
	delete[] _arr;
	_arr = new_arr;
	_size--;
}

template<class T>
inline void Array<T>::sort()
{
	T temp = _arr[0];
	int temp_k = 0;
	T ko = 200;
	for (int i = 0; i < _size; i++)
	{
		temp = _arr[i];
		for (int k = i; k < _size; k++)
		{
			if (temp > _arr[k]) {
				temp = _arr[k];
				temp_k = k;

			}
		}
		if (ko != temp_k) {
			_arr[temp_k] = _arr[i];
			_arr[i] = temp;
			ko = temp_k;
		}

	}
}


