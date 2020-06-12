#include "Book.h"
#include <iostream>


Book::Book(Book& obj)
{
	autor = obj.autor_name();
	name = obj.book_name();
	publisher = obj.publisher_name();
	year = obj.published_year();
	page = obj.page_quantity();

}

Book::Book()
{
	//std::cout << "Book()";
}

Book::Book(std::string value)
{
	//std::cout << "Book(std::string value)\n";
	name = value;
}

Book::Book(int value)
{
	//std::cout << "Book(int value)\n";
	year = value;
}

Book::Book(std::string name, std::string autor, std::string publisher, int year, int page)
{
	this->name = name;
	this->autor = autor;
	this->publisher = publisher;
	this->year = year;
	this->page = page;
}

Book::~Book()
{
}

std::string Book::book_name() const
{
	return name;
}

std::string Book::autor_name() const
{
	return autor;
}

std::string Book::publisher_name()const
{
	return publisher;
}

int Book::published_year()const
{
	return year;
}

int Book::page_quantity()const
{
	return page;
}

void Book::book_name(std::string value)
{
	name = value;
}

void Book::autor_name(std::string value)
{
	autor = value;
}

void Book::publisher_name(std::string value)
{
	publisher = value;
}

void Book::published_year(int value)
{
	year = value;
}

void Book::page_quantity(int value)
{
	page = value;
}
