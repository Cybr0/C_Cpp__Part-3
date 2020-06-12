#pragma once
#include <string>
class Worker
{
public:
	Worker();
	~Worker();
	std::string getName();
	void setName(std::string);
	double getOklad();
	void setOklad(double);
	double getMinimal();
	void setMinimal(double);
	double getTax();
	void setTax(double);
	double get_salary();
	double get_result_salary();
	static double s_minimal;//не хорошо
	static void setTaxStatic(double);
private:
	std::string w_name;
	double s_oklad;
	static double s_tax;
};

