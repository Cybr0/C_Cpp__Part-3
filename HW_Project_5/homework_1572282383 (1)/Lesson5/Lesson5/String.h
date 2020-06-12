#pragma once
class String
{
public:
	String();
	String(size_t lenght);
	String(const char *value);
	String(String& val);
	~String();
	void setString(const char* value);
	String& addString(const char* value);
	const char* getData();
	
private:
	char* data;
	size_t data_length;
};

