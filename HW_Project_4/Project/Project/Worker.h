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
	void setMinimal(double);
	static double getTax();
	void setTax(double);
	double get_salary();
	double get_result_salary();
	static int Length();
	static void setTaxStatic(double);
	static double** YearInfo();
	static void showAnnualReport();
	static void salaryYearInfo(int l, double** yearInfo, int tmp_c, int i = 0);
private:
	static double s_minimal;
	std::string w_name;
	double s_oklad;
	static double s_tax;
	static int length; // month arr, for func salaryYearInfo()
	static int col;
	static double **yearInfo;
};

