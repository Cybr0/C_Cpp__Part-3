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
		for (size_t i = 0; i < Object.size(); i++) {
			push_back(Object[i]);
		}
	}
	~Deque() { if (data_back) { clear(); } }
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
	void clear() {
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
	const T& operator[](size_t index) {
	//	if (_size > index) {
			item_data<T> *temp_data = data_front;
			for (size_t i = 0; i < index; i++)
			{
				temp_data = temp_data->next;
			}
			return temp_data->value;
	//	}	
	}
	Deque<T>& operator=(const Deque<T>& DEQ){
		if (data_back) {
			clear();
		}
		size_t tmp_size = 0;
		item_data<T>* tmp_data_front = DEQ.data_front;
		while (tmp_size < DEQ._size)
		{
			push_back(tmp_data_front->value);
			tmp_data_front = tmp_data_front->next;
			tmp_size++;
		}
		return *this;
	}
		
private:
	item_data<T>* data_back;
	item_data<T>* data_front;
	size_t _size;
};
