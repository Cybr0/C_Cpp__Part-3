#pragma once
#include <iostream>
#include "Book.h"

class Library
{
public:
	Library();
	~Library();
	void add_book(Book new_item);
	void rem_book(size_t index);

	void show_by_autor(std::string name) const;
	void show_by_publisher(std::string name) const;
	void show_after_year(int) const;

private:
	Book* book_list;
	size_t size;
};

