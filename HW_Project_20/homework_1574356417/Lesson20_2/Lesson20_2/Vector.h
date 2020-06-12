#pragma once
//#include "deque.h"

template<typename U>
class Vector :public Deque<U> {
	public:
		Vector(const std::initializer_list<T>& list) :Deque<U>(list) {}
		Vector() : Deque<U>() {}
		Vector(Vector& Object) :Deque<U>(Object) {}
		~Vector(){}

		item_data<T>* operator[](size_t i) {
			if (i >= _size) i = 0;


		}
	};


