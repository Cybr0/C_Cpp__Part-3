#pragma once
#include <iostream>
template<class U>
class list_item {
public:
	list_item() {
		next = nullptr;
		prev = nullptr;
	}
	U data;
	list_item<U>* next;
	list_item<U>* prev;
};

template<class T>
class Stack {
public:
	Stack() { _size = 0; item = nullptr; }
	Stack(const std::initializer_list<T>& list);
	~Stack() {}
	void push(T);
	T pop();
	size_t size();
private:
	size_t _size;
	list_item<T> *item;
};

template<class T>
inline Stack<T>::Stack(const std::initializer_list<T>& list)
{
	for (T item : list) {
		push(item);
	}
}

template<class T>
inline void Stack<T>::push(T value)
{
	list_item<T>* new_item = new list_item<T>();
	new_item->data = value;
	if (item) {
		item->next = new_item;
		new_item->prev = item;
	} 
	item = new_item;
	_size++;
}

template<class T>
inline T Stack<T>::pop()
{
	T ret_val;
	if (item) {
		ret_val = item->data;
		if (item->prev) {
			item = item->prev;
			delete item->next;
			item->next = nullptr;
		} else {
			delete item;
			item = nullptr;
		}
		_size--;
	}
	return ret_val;
}

template<class T>
inline size_t Stack<T>::size()
{
	return _size;
}
