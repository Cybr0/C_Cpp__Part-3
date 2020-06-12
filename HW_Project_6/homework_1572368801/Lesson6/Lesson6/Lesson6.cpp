#include <iostream>
#include "Book.h"
#include "Library.h"

int main()
{
	Book b = std::string("New book");
	std::string str = "Timur";
	b.autor_name(str);
	b.published_year(2019);
	b.publisher_name("Tashkent");

	Book b2 = std::string("New book");
	str = "Shamsiddin";
	b2.autor_name(str);
	b2.published_year(2020);
	b2.publisher_name("Tashkent");

	Book b3 = std::string("book");
	str = "Timur";
	b3.autor_name(str);
	b3.published_year(2021);
	b3.publisher_name("Tashkent");
	

	Library boo;
	boo.add_book(b);
	boo.add_book(b2);
	boo.add_book(b3);
	std::cout << "__________________________________________________\n\n";
	boo.show_after_year(2019);
	std::cout << "__________________________________________________\n\n";
	boo.show_by_autor("Timur");
	std::cout << "__________________________________________________\n\n";
	boo.rem_book(1);
	boo.show_by_publisher("Tashkent");
}

