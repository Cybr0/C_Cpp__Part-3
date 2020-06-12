#pragma once
#include <string>
class String
{
public:
	String();
	String(int );
	String(const char* );
	~String();
	char* GetString();
	void SetString(const char* );
	int Quantity();
	int GetID();
private:
	void QuantityForConstructor_And_ID();
	int id;
	static int quantity;
	char* string;
	int size;

};

