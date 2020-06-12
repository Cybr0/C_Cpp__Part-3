#pragma once
#include <fstream>
#include <string>


class ReadFile
{
public:
	ReadFile() { fromFile = ""; }
	~ReadFile(){}
	virtual void Display(const char* path) {
		std::ifstream fin(path);
		if (fin.is_open()) {
			char ch;
			while (fin.get(ch))
			{
				fromFile += ch;
			}
		}
	}
	std::string& data() { return fromFile; }
protected:
	std::string fromFile;
};

class ReadFileASCII : public ReadFile
{
public:
	ReadFileASCII() : ReadFile() {}
	~ReadFileASCII() {}
	virtual void Display(const char* path) override {
		std::ifstream fin(path);
		if (fin.is_open()) {
			char ch;
			int toInt;
			while (fin.get(ch))
			{
				toInt = ch;
				fromFile += std::to_string(toInt);
			}
		}
	}
protected:

};


class ReadFileBinary : public ReadFile
{
public:
	ReadFileBinary() : ReadFile() {}
	~ReadFileBinary() {}
	virtual void Display(const char* path) override {
		std::ifstream fin(path);
		if (fin.is_open()) {
			char ch;
			int toInt;
			while (fin.get(ch))
			{
				toInt = ch;
				do
				{
					fromFile += std::to_string((toInt % 2));
					toInt /= 2;
				} while (toInt != 0);
					
			}
		}
	}
protected:
	
};
