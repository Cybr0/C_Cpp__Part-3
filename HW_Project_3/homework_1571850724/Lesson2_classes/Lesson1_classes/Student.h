#pragma once
#include <string>

class Student
{
public:
	Student();//constructor
	Student(std::string n);
	Student(std::string n, std::string d);
	~Student();//destructor
	void Name(std::string data) {//inline method 1
		name = data;
	}
	std::string Name();
	void Date(std::string);
	std::string Date();
	void Group(std::string);
	std::string Group();
	void Val(int v) {
		value = v;
	}
	int Val() {
		return value;
	}

	void Address(const char *val) {
		strcpy_s(address, 19, val);
	}
	const char* Address() {
		return address;
	}
private:
	std::string name;
	std::string birthDate;
	std::string group;
	char* address;
	int value;
};

inline std::string Student::Name()//inline method 2
{
	return name;
}

