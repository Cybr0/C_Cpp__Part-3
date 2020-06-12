#pragma once
#include <string>
class Book
{
public:
	Book(Book&);
	Book();
	Book(std::string);
	explicit Book(int);
	Book(std::string name,std::string autor,std::string publisher,int year,int page);
	~Book();
	std::string book_name() const;
	std::string autor_name() const;
	std::string publisher_name()const;
	int published_year()const;
	int page_quantity()const;

	void book_name(std::string);
	void autor_name(std::string);
	void publisher_name(std::string);
	void published_year(int);
	void page_quantity(int);

private:
	std::string name;
	std::string autor;
	std::string publisher;
	int year;
	int page;
};

