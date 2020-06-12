#pragma once
#include "deque.h"

template<typename T>
class Stack :public Deque<T> {
public:
	Stack(const std::initializer_list<T>& list) :
		Deque(list) {}

	Stack(Stack& Object){
		*this = Object;
	}

	Stack():Deque<T>() {}
	~Stack() {}
	void push(T item){
		Deque<T>::push_back(item);
	}
	T pop() {
		T ret_val = Deque<T>::back_value();
		Deque<T>::pop();
		return ret_val;
	}
};
