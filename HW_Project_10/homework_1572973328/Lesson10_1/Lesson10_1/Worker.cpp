#include "Worker.h"

Worker::Worker()
{
	
}


Worker::~Worker()
{
}

std::string Worker::name()
{
	return _name;
}

double Worker::salary()
{
	return _salary;
}

int Worker::stage()
{
	return _stage;
}

std::ostream& operator<<(std::ostream& out, Worker& obj)
{
	
	out << "name:" << obj.name() << "\nstage:10\nsalary:100.00";
	return out;
	
}
