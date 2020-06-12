#pragma once
#include <string>

class Worker
{
public:
	Worker();
	~Worker();
	std::string name();
	double salary();
	int stage();

	Worker& operator=(const char* value) {
		_name = std::string(value);
		return *this;
	}

	Worker& operator=(std::string& value) {
		_name = value;
		return *this;
	}
	Worker& operator=(double value) {
		_salary = value;
		return *this;
	}
	Worker& operator=(int value) {
		_stage = value;
		return *this;
	}

	bool operator!=(Worker& a) {
		return ((_name != a._name) || (_salary != a._salary) ||	(_stage != a._stage));
	}

	bool operator<(Worker& a) {
		int tmp = _name.compare(a._name);
		return (tmp > 0);
	}

	bool operator>(Worker& a) {
		int tmp = _name.compare(a._name);
		return (tmp < 0);
	}
	operator std::string() {
		return _name;
	}
	operator double() {
		return _salary;
	}
	operator int() {
		return _stage;
	}
private:
	std::string _name;
	double _salary;
	int _stage;
};

