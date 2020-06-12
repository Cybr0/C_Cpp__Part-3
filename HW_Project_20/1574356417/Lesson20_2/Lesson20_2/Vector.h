#pragma once
#include "deque.h"

template<typename T>
class Vector :public Deque<T> {
public:
	//TODO: constructors overload
	//TODO:[] overload &
	void push_back(T) {
		//TODO:
	}
	bool insert(size_t index, T value) {
		//TODO:
	}
	T get(size_t index) {
		//TODO:[]
		//
		_size = 0;
		return T();
	}
};
