#pragma once
template<class T>
class dynamic_array_stack
{
public:
	dynamic_array_stack(int count);
	~dynamic_array_stack();
	bool push(T);
	void pop();
	const T& top();
	bool empty();
	int size();
private:
	T* data;
	int last_item;
	int max_count;
};



template<class T>
dynamic_array_stack<T>::dynamic_array_stack(int count) :
	max_count{ count },
	last_item{ -1 }
{
	data = new T[max_count];
}

template<class T>
dynamic_array_stack<T>::~dynamic_array_stack()
{
	delete[] data;
}
template<class T>
bool dynamic_array_stack<T>::push(T temp)
{
	last_item++;
	if (max_count > last_item) {
		data[last_item] = temp;
		return true;
	}
	return false;
}

template<class T>
void dynamic_array_stack<T>::pop()
{
	if (last_item > -1) {
		last_item--;
	}
}

template<class T>
const T& dynamic_array_stack<T>::top()
{
	if (last_item >= 0) {
		return data[last_item];
	}
	return T();
}

template<class T>
bool dynamic_array_stack<T>::empty()
{
	return (last_item < 0);
}

template<class T>
int dynamic_array_stack<T>::size()
{
	return (last_item + 1);
}

