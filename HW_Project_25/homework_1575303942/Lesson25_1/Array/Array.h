#pragma once
namespace linear{
class Array
{
public:
	Array()
	{
		_size = 0;
		_capacity = limit;
		array = new int[_capacity];
	}
	~Array() {}
	int size() const{
		return _size;
	}
	int capacity() const {
		return _capacity;
	}
	void push_back(int value) {
		if (_size < _capacity) {
			array[_size] = value;

		}
		else {
			_capacity += limit;
			int* new_array = new int[_capacity];
			for (int i = 0; i < _size; i++) {
				new_array[i] = array[i];
			}

			new_array[_size] = value;

			delete[] array;
			array = new_array;
		}
		_size++;
	}
	int& operator[](int i) {
		if (i >= _size) {
			return array[_size - 1];
		}
		return array[i];
	}
	Array& operator()(int i, int val) {
		operator[](i) = val;
		return *this;
	}
	void operator()(int value) {
		for (int i = 0; i < _size; i++) {
			array[i] += value;
		}
	}
private:
	int _size, _capacity;
	const int limit = 10;
	int* array;
};
}

