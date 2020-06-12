#pragma once
#include <iostream>
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
	static double getMinimal();
	static void setMinimal(double);
	static double getTax();
	static void setTax(double);
	double get_salary();
	double get_result_salary();
	//static int Length();
	static void setTaxStatic(double);
	
	static void showAnnualReport();
	static void salaryYearInfo(double yearInfo[12][2], int tmp_c, int i = 0);
	static double yearInfo[12][2];
private:
	static double s_minimal;
	std::string w_name;
	double s_oklad;
	static double s_tax;
	//static const int length; // month arr, for func salaryYearInfo()
	//static const int col;
	
};

