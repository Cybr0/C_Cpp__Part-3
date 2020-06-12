#pragma once
class valuta
{
public:
	valuta();
	~valuta();


	double _value();
	void _type(int type);
	
	double& operator+(double value);
	valuta& operator+(valuta& other);
	double& operator-(double value);
	valuta& operator-(valuta& other);
	double& operator*(double value);
	valuta& operator*(valuta& other);
	double& operator/(double value);
	valuta& operator/(valuta& other);
	double& operator=(double value);
	valuta& operator=(valuta& other);
	bool operator==(double value);
	bool operator==(valuta& other);
	bool operator<(double value);
	bool operator<(valuta& other);
	bool operator>(double value);
	bool operator>(valuta& other);
	valuta& operator++();
	valuta& operator++(int opp);
	valuta& operator--();
	valuta& operator--(int opp);

	
private:
	int type;
	double value;
	enum cur_type
	{
		ct_usd = 1,
		ct_uzs
	};
	void _check_type(valuta& other);
};

