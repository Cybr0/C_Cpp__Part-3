#include "Library.h"



Library::Library()
{
	size = 0;
}


Library::~Library()
{
	if (book_list != nullptr)
		delete[] book_list;
}

void Library::add_book(Book new_item) 
{
	Book* arr = new Book[size+1];
	for (size_t i = 0; i < size; i++) {
		arr[i] = book_list[i];
	}	
	arr[size] = new_item;
	if(size > 0){
		delete[]book_list;
	}
	book_list = arr;
	size++;
}

void Library::rem_book(size_t index)
{
	Book* arr = new Book[size - 1];
	int k = 0;
	for (size_t i = 0; i < size; i++) {
		if (i != index)
		{
			arr[k] = book_list[i];
			k++;
		}
	}
	
	if (size > 0) {
		delete[]book_list;
	}
	book_list = arr;
	size--;
}

void Library::show_by_autor(std::string name) const
{
	std::cout << "Founded book by autor name: "<< name << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if(book_list[i].autor_name() == name)
		{
			std::cout << book_list[i].book_name() << std::endl;
			std::cout << book_list[i].autor_name() << std::endl;
			std::cout << book_list[i].publisher_name() << std::endl;
			std::cout << book_list[i].published_year() << std::endl << std::endl;
		}
	}
}

void Library::show_by_publisher(std::string name) const
{
	std::cout << "Founded book by publisher name: " << name << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if (book_list[i].publisher_name() == name)
		{
			std::cout << book_list[i].book_name() << std::endl;
			std::cout << book_list[i].autor_name() << std::endl;
			std::cout << book_list[i].publisher_name() << std::endl;
			std::cout << book_list[i].published_year() << std::endl << std::endl;
		}
	}
}

void Library::show_after_year(int year) const
{
	std::cout << "Founded book by published year: " << year << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if (book_list[i].published_year() >= year)
		{
			std::cout << book_list[i].book_name() << std::endl;
			std::cout << book_list[i].autor_name() << std::endl;
			std::cout << book_list[i].publisher_name() << std::endl;
			std::cout << book_list[i].published_year() << std::endl << std::endl;
		}
	}
}
