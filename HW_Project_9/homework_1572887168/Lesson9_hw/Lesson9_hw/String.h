#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>

class String
{
public:
	String();
	String(const char*);
	String(String&);
	~String();
	void set_data(const char* v);
	void add_data(const char* v);
	const char* data(); 
	size_t size();
	String& operator=(const char*dfdf) {
		set_data(dfdf);
		return *this;
	}
	String& operator=(String& v) {
		set_data(v.data());
		return *this;
	}
	String& operator+=(const char* v) {
		add_data(v);
		return *this;
	}
	bool operator<(String& v)  {
		return is_gen(v.data(), value);
	}
	std::ostream& operator << (std::ostream& out) {
		out << value;
		return out;
	}
	std::istream& operator >> (std::istream& in) {
		in >> value;
		return in;
	}
	char& operator[](size_t index);
	bool operator==(const char* other);
	
private:
	char *value;
	size_t val_size;
	bool is_gen(const char* first, const char* second);
};
