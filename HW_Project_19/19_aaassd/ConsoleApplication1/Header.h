#pragma once
#include <iostream>
#include <string>

class Mammal
{
public:
	Mammal() {
		pawCount = 0;
	}
	Mammal(int pawCount) {
		this->pawCount = pawCount;
	}
	Mammal(Mammal& mammal) {
		pawCount = mammal.pawCount;
	}
	void PawCount(int pawCount) {
		this->pawCount = pawCount;
	}
	int& PawCount() {
		return pawCount;
	}

	~Mammal(){}

protected:
	int pawCount;
};



class Pet: public Mammal
{
public:
	Pet():Mammal(){
		nickname = "";
		age = 0;
		weight = 0;
	}
	Pet(std::string nickname, int age, int weight, int pawCount):Mammal(pawCount) {
		this->nickname = nickname;
		this->age = age;
		this->weight = weight;
	}
	Pet(Pet& pet) {
		this->nickname = pet.nickname;
		this->age = pet.age;
		this->weight = pet.weight;
		this->pawCount = pet.pawCount;
	}
	~Pet(){}
	virtual void voice() { std::cout << "Voice!!" << std::endl; };
	void Nickname(std::string nickname) {
		this->nickname = nickname;
	}
	std::string& Nickname() {
		return nickname;
	}
	void Age(int age) {
		this->age = age;
	}
	int& Age() {
		return age;
	}
	void Weight(int weight) {
		this->weight = weight;
	}
	int& Weight() {
		return weight;
	}
protected:
	std::string nickname;
	int age;
	int weight;

};

class Cat: public Pet
{
public:
	Cat():Pet() {}
	Cat(std::string nickname, int age, int weight, int pawCount):Pet(nickname, age, weight, pawCount) {}
	Cat(Cat& cat) :Pet(cat) {}
	~Cat(){}
	virtual void voice() override { std::cout << "Meow!!" << std::endl; }

private:

};

class Dog : public Pet
{
public:
	Dog():Pet() {}
	Dog(std::string nickname, int age, int weight, int pawCount) :Pet(nickname, age, weight, pawCount) {}
	Dog(Dog& dog):Pet(dog) {}
	~Dog(){}
	virtual void voice() override{ std::cout << "Woof!!" << std::endl; }

private:

};

class Bird : public Pet
{
public:
	Bird():Pet() {}
	Bird(std::string nickname, int age, int weight, int pawCount) :Pet(nickname, age, weight, pawCount) {}
	Bird(Bird& Bird) :Pet(Bird) {}
	~Bird(){}
	virtual void voice() override{ std::cout << "Kraa-kraa!!" << std::endl; }

private:
	int wingCount;
	std::string beakType;
};

