#include <iostream>
#include "String.h"

template <typename T>
void selectSort(T a[], size_t size) {
	int k;
	T x;
	for (int i = 0; i < size; i++) {   	// i - номер текущего шага
		k = i;
		x = a[i];
		for (int j = i + 1; j < size; j++) {	// цикл выбора наименьшего элемента
			if (a[j] < x) {
				k = j;
				x = a[j];	        // k - индекс наименьшего элемента
			}
		}
		a[k] = a[i];
		a[i] = x;   	// меняем местами наименьший с a[i]
	}
}

int main()
{
	const size_t length = 5;
	String str[length];
	str[0] = "The";
	str[1] = "write";
	str[2] = "function";
	str[3] = "example";
	str[4] = "showed";

	for (size_t i = 0; i < length; i++) {
		std::cout << str[i].data() << std::endl;
	}
	selectSort(str, length);
	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < length; i++) {
		std::cout << str[i].data() << std::endl;
	}
}
