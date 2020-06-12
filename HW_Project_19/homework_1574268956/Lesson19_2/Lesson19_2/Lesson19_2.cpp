#include <iostream>
#include <string>
#include <vector>
#include <array>

class Database {
	void write_to_db(std::string value) {
		std::cout << "database write:" <<value << std::endl;
	}
};

class Student {
public:
	Student() {
	}
	std::string name;
	int age;
};

class Group {
public:
	Group(Database* db_obj){
		db = db_obj;
	}
	std::string name;
	Database* db; //Агрегация
	std::vector<Student> students;//Композиция
};

int main()
{
	Database my_stat;

	Group gr_1(&my_stat);
	Group gr_2(&my_stat);
	
}
