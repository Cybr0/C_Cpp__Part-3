#pragma once
template<typename T>
class item_data {
public:
	item_data() : prev{ nullptr }, next{ nullptr }, value{T()} {}
	T value;
	item_data<T> *prev;
	item_data<T> *next;
};

template<typename T>
class Deque
{
public:
	Deque() :head{ nullptr }, tail{ nullptr }, _size{0} {}
	~Deque(){}
	void push_back(T);
	void push_front(T);
	void pop();
	const T& back_value();
	void clear();
	size_t size();
private:
	item_data<T>* head;
	item_data<T>* tail;
	size_t _size;
};

template<typename T>
inline void Deque<T>::push_back(T value)
{
	item_data<T> tmp_data_back = new T(head);
	item_data<T> tmp_data = new T;
	tmp_data.value = value;
	if (tmp_data_back)
	{
		while (tmp_data_back->next)
		{
			tmp_data_back = tmp_data_back->next;
		}
		tmp_data_back->next = tmp_data;
		tmp_data->prev = tmp_data_back;
	}
	else
	{
		head = tmp_data;
		tail = head;
	}
}

template<typename T>
inline void Deque<T>::push_front(T)
{
	item_data<T> tmp_data_front = new T(tail);
	item_data<T> tmp_data = new T;
	tmp_data.value = value;
	if (tmp_data_front)
	{
		while (tmp_data_front->next)
		{
			tmp_data_back = tmp_data_back->next;
		}
		tmp_data_back->next = tmp_data;
		tmp_data->prev = tmp_data_back;
	}
	else
	{
		tail = tmp_data;
		head = tail;
	}
}

template<typename T>
inline void Deque<T>::pop()
{
}
