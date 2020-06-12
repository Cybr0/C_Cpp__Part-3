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
	friend std::ostream& operator << (std::ostream& out, String& data);
	friend std::istream& operator >> (std::istream& out, String& data);
	
private:
	char *value;
	size_t val_size;
	bool is_gen(const char* first, const char* second);
};
