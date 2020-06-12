#include <initializer_list>
#pragma once
template<typename T>
class item_data {
public:
	item_data() {
		prev = nullptr;
		next = nullptr;
	}
	T value;
	item_data<T> *prev;
	item_data<T> *next;
};

template<typename T>
class Deque
{
public:
	Deque(const std::initializer_list<T>& list):Deque(){
		for (auto item : list) {
			push_back(item);
		}
	}
	Deque(){
		data_back = nullptr;
		data_front = nullptr;
		_size = 0;
	}

	Deque(Deque&Object):Deque(){
		*this = Object;
	}
	~Deque() { clear();}
	
	void clear() {
		if (!data_back) {
			return;
		}
		while (data_back->prev)
		{
			data_back = data_back->prev;
			delete data_back->next;
		}
		delete data_back;
		data_back = nullptr;
		data_front = nullptr;
		_size = 0;
	}
	size_t size() {
		return _size;
	}
	
	const Deque<T>& operator=(Deque&obj) {
		item_data<T>* temp_data = obj.data_front;
			while (temp_data)
			{
				push_back(temp_data->value);
				temp_data = temp_data->next;
			}
			return *this;
	}
	//const T& operator[](size_t index) {
	////	if (_size > index) {
	//		item_data<T> *temp_data = data_front;
	//		for (size_t i = 0; i < index; i++)
	//		{
	//			temp_data = temp_data->next;
	//		}
	//		return temp_data->value;
	////	}	
	//}
protected:
	void push_back(T val) {
		item_data<T>* new_item = new item_data<T>;
		new_item->value = val;

		if (data_back) {
			data_back->next = new_item;
			new_item->prev = data_back;
		}
		else {
			data_front = new_item;
		}
		data_back = new_item;
		_size++;
	}
	void push_front(T val) {
		item_data<T>* new_item = new item_data<T>;
		new_item->value = val;

		if (data_front) {
			data_front->prev = new_item;
			new_item->next = data_front;
		}
		else {
			data_back = new_item;
		}
		data_front = new_item;
		_size++;
	}
	void pop() {
		if (data_back) {
			if (data_back->prev)
			{
				data_back = data_back->prev;
				delete data_back->next;
				data_back->next = nullptr;
			}
			else {
				delete data_back;
				data_back = nullptr;
				data_front = nullptr;
			}
			_size--;
		}
	}
	const T& back_value() {
		return data_back->value;
	}
	item_data<T>* data_back;
	item_data<T>* data_front;
	size_t _size;
};
