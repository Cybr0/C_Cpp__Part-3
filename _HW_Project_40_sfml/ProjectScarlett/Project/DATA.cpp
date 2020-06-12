#include "DATA.h"
#include <iostream>
#include <string>
Data::Data()
{
}

Data::~Data()
{
}

Data& Data::operator=(Data& obj)
{
	//std::vector<Flight>* tmp_flight = new std::vector<Flight>;
	flight = obj.flight;
	user = obj.user;
	return obj;
}


std::vector<User>& Data::getUser() {
	return user;
}

std::vector<Flight>& Data::getFlight() {
	return flight;
}

bool Data::changePassword(std::string& login, Textbox& tbox) {
	std::cout << "\t\t\t***��������� ������***" << std::endl;
	std::string prev;
	std::cout << "���������� ������ ������ : ";
	std::cin >> prev;
	for (size_t i = 0; i < user.size(); i++) {
		if (login == user[i].getLogin() && prev == user[i].getPassword()) {
			std::string newpas;
			std::cout << "������� ����� ������ : ";
			std::cin >> newpas;
			user[i].setPassword(newpas);
			std::cout << "������ ������� ������..." << std::endl; return true;
		}
		else {
			std::cout << "������������ ������..." << std::endl;
			return false;
		}
	}
	return false;
}

void Data::addCashier()
{
	User tmp;
	bool ok = true;
	while (ok) {
		std::cout << "������� ����� : ";
		std::cin >> tmp.getLogin();
		for (size_t i = 0; i < user.size(); i++) {
			if (user[i].getLogin() == tmp.getLogin()) {
				std::cout << "������ ����� ��� �����." << std::endl;
				ok = false;
				break;
			}
		}
		if (ok == false) { ok = true; }
		else { ok = false; }
	}
	std::cout << "������� ������ : ";
	std::cin >> tmp.getPassword();
	std::cout << "������� ��� : ";
	std::cin >> tmp.getFullName();
	user.push_back(tmp);
	std::cout << "������� ������." << std::endl;

}

bool Data::deleteCashier()
{
	std::cout << "\t\t\t�������� �������" << std::endl << std::endl;
	std::string login;
	std::cout << "������� ����� ���������� ������� : ";
	std::cin >> login;
	for (size_t i = 0; i < user.size(); i++) {
		if (login == user[i].getLogin()) {
			if (user[i].getRights() == accessRights(1)) {
				std::cout << "������ ������� ������..." << std::endl;
			}
			user.erase(user.begin() + i);
			std::cout << "������ �����." << std::endl; return true;
		}
	}
	std::cout << "������� �� ������" << std::endl;
	return false;
}

bool Data::changeCashierInfo()
{
	std::string login;
	std::cout << "������� ����� ������� ������� : ";
	std::cin >> login;
	for (size_t i = 0; i < user.size(); i++) {
		if (login == user[i].getLogin()) {
			std::cout << "������� ����� ��� : ";
			std::cin >> user[i].getFullName();
			std::cout << "������� ����� ����� : ";
			std::cin >> user[i].getLogin();
			std::cout << "������� ����� ������ : ";
			std::cin >> user[i].getPassword();
			return true;
		}
	}
	std::cout << "������� �� ������" << std::endl;
	return false;
}

void Data::FlightInfo() {
	for (size_t i = 0; i < flight.size(); i++) {
		std::cout << "ID : " << i << std::endl;
		std::cout << "Airline : " << flight[i].getAirline() << std::endl;
		std::cout << "Flight Number : " << flight[i].getFlightNumber() << std::endl;
		std::cout << "From To : " << flight[i].getFrom_to() << std::endl;
		std::cout << "Date From To : " << flight[i].getDate_from_to() << std::endl;
		std::cout << "Time From To : " << flight[i].getTime_from_to() << std::endl;
		std::cout << "Count Ticket : " << flight[i].getTicket().size() << std::endl;
		std::cout << "Flight Number : " << flight[i].getFlightNumber() << std::endl;
		std::cout << "�������� / �� �������� (1 / 0) : " << flight[i].getAvailable() << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
}

bool Data::findFlight()
{
	std::cout << "\t\t\t***����� �� ������***" << std::endl << std::endl;
	int type;
	std::cout << "1. ����� �� �����������." << std::endl;
	std::cout << "2. ����� �� ����." << std::endl << std::endl; std::cout << "������� ����� : ";
	std::cin >> type;
	if (type == 1) {
		system("cls");
		std::cout << "\t\t\t*** ����� �� ����������� ***" << std::endl << std::endl;
		std::string org_des;
		bool ok = true;
		bool ok1 = false;
		while (ok) {
			std::cout << "������� ����������� : ";
			std::cin >> org_des;
			std::cout << " ID |Origin/Destination | Time / Time | Airline | Flight Number | Tickets | Date " << std::endl << std::endl;
			for (size_t i = 0; i < flight.size(); i++)
			{
				for (size_t j = 0; j < org_des.size(); j++)
				{
					if (org_des[j] == flight[i].getFrom_to()[j])
					{
						ok1 = true;
						if (j == org_des.size() - 1)
						{
							std::cout << "  " << i << " | "
								<< flight[i].getFrom_to() << " | "
								<< flight[i].getTime_from_to() << " | "
								<< flight[i].getAirline() << " | "
								<< flight[i].getFlightNumber() << " | "
								<< flight[i].getTicket().size()
								<< flight[i].getDate_from_to() << std::endl;
						}
					}
				}
			}
			if (ok1 == true) { return true; }
			std::cout << "���� �� ������" << std::endl;
			std::cout << "��������� �������" << std::endl;
		}
	}
	else if (type == 2) {
		system("cls");
		std::string date;
		bool ok = true;
		while (ok) {
			std::cout << "������� ���� : ";
			std::cin >> date;
			for (size_t i = 0; i < flight.size(); i++) {
				if (date == flight[i].getDate_from_to()) {
					std::cout << " ID |Origin/Destination | Time / Time | Airline | Flight Number | Tickets | Date" << std::endl;
					std::cout << "  " << i << " | "
						<< flight[i].getFrom_to() << " | "
						<< flight[i].getTime_from_to() << " | "
						<< flight[i].getAirline() << " | "
						<< flight[i].getFlightNumber() << " | "
						<< flight[i].getTicket().size() << " | "
						<< flight[i].getDate_from_to() << std::endl;
					return true;
				}
			}
			std::cout << "���� �� ������." << std::endl;
			std::cout << "�������� ������" << std::endl;
		}
	}
	return false;
}

void Data::availableFlight()
{
	for (size_t i = 0; i < flight.size(); i++) {
		if (flight[i].getAvailable() == true) {
			std::cout << "ID : " << i << std::endl;
			std::cout << "Airline : " << flight[i].getAirline() << std::endl;
			std::cout << "Flight Number : " << flight[i].getFlightNumber() << std::endl;
			std::cout << "From To : " << flight[i].getFrom_to() << std::endl;
			std::cout << "Date From To : " << flight[i].getDate_from_to() << std::endl;
			std::cout << "Time From To : " << flight[i].getTime_from_to() << std::endl;
			std::cout << "Count Ticket : " << flight[i].getTicket().size() << std::endl;
			std::cout << "-----------------------------------------------------------" << std::endl;
		}
	}
}

void Data::sellTicket()
{
	system("cls");
	std::cout << "\t\t\t***������� �������***" << std::endl << std::endl;
	availableFlight();
	int id;
	std::cout << "������� ID ���������� ����� : ";
	std::cin >> id;
	try {
		if (id >= flight.size()) {
			throw "Index Error";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	system("cls");
	std::cout << " ID | Class Type | Seat Number | Price" << std::endl << "--------------------------------------" << std::endl;
	for (size_t j = 0; j < flight[id].getTicket().size(); j++) {
		bool sold = flight[id].getTicket()[j].getSold();
		if (sold == false) {
			std::cout << j << " | " << flight[id].getTicket()[j].getClassType() << " | " << flight[id].getTicket()[j].getSeatNumber() << " | " << flight[id].getTicket()[j].getPrice() << std::endl;
		}
	}
	int pos;
	std::cout << "�������� ����� �� ID : "; std::cin >> pos;
	try {
		if (pos >= flight[id].getTicket().size()) {
			throw "Index Error";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	flight[id].getTicket()[pos].setSold(true);
	std::string name; std::cout << "������� ��� : "; std::cin >> name;
	flight[id].getTicket()[pos].setNameOfPassanger(name);
	std::cout << "������� ���������� ������ : "; std::cin >> name;
	flight[id].getTicket()[pos].setDataOfPassanger(name);
	bool bag; std::cout << "����� : "; std::cin >> bag;
	flight[id].getTicket()[pos].setBaggage(bag); std::cout << std::endl;
	std::cout << "����� ������" << std::endl;
}

void Data::cancelTicket()
{
	std::cout << "\t\t\t***������ ��������� �������***" << std::endl << std::endl;
	availableFlight();
	std::cout << "�������� ���� �� ID : ";
	int id; std::cin >> id;
	try {
		if (id >= flight.size()) {
			throw "Index Error";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	system("cls");
	std::cout << " ID | Class Type | Seat Number | Price | Full Name | Passport " << std::endl << "--------------------------------------" << std::endl;
	for (size_t j = 0; j < flight[id].getTicket().size(); j++) {
		bool sold = flight[id].getTicket()[j].getSold();
		if (sold == true) {
			std::cout << j << " | "
				<< flight[id].getTicket()[j].getClassType()
				<< " | " << flight[id].getTicket()[j].getSeatNumber()
				<< " | " << flight[id].getTicket()[j].getPrice()
				<< " | " << flight[id].getTicket()[j].getNameOfPassanger()
				<< " | " << flight[id].getTicket()[j].getDataOfPassanger() << std::endl;
		}
	}
	int pos;
	std::cout << "������� ����� �� ID: "; std::cin >> pos;
	try {
		if (pos >= flight[id].getTicket().size()) {
			throw "Index Error";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	flight[id].getTicket()[pos].setSold(false);
}

void Data::addFlight()
{
	std::cout << "\t\t\t***���������� ������***" << std::endl << std::endl;
	Flight tmp;
	std::cout << "������� ������������ : "; std::cin >> tmp.getAirline();
	std::cout << "������� �����������(FROM / TO) : "; std::cin >> tmp.getFrom_to();
	std::cout << "������� ����(����� / ���) : "; std::cin >> tmp.getDate_from_to();
	std::cout << "������� ����� (����� / �����) : "; std::cin >> tmp.getTime_from_to();
	std::cout << "������� ���������� ������� : ";
	int ctr; std::cin >> ctr;
	for (size_t i = 0; i < ctr; i++) {
		tmp.getTicket().push_back(Ticket());
	}
	bool ok = true;
	while (ok) {
		std::cout << "������� ����� ����� : "; std::cin >> tmp.getFlightNumber();
		for (size_t i = 0; i < flight.size(); i++) {
			if (tmp.getFlightNumber() == flight[i].getFlightNumber()) {
				std::cout << "��������� �������" << std::endl; ok = false; break;
			}
		}
		if (ok == false) { ok = true; }
		else { ok = false; }
	}
	flight.push_back(tmp);
	std::cout << "���������� �������" << std::endl;
}

void Data::deleteFlight()
{
	system("cls");
	std::cout << "\t\t\t***�������� ������***" << std::endl << std::endl;
	availableFlight();
	int pos;
	std::cout << "������� ID : "; std::cin >> pos;
	flight.erase(flight.begin() + pos);
	std::cout << "���� ������� �����" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
}

void Data::changeFlight()
{
	std::cout << "\t\t\t***��������� ������***" << std::endl << std::endl;
	FlightInfo();
	int id;
	std::cout << "������� ��������� ���� �� ID : "; std::cin >> id;
	try {
		if (id >= flight.size()) {
			throw "Index Error";
		}
	}
	catch (const char* p) {
		std::cout << "Error  : " << p << std::endl;
	}

	std::cout << "������� ������������ : "; std::cin >> flight[id].getAirline();
	std::cout << "������� ����������� : "; std::cin >> flight[id].getFrom_to();
	std::cout << "������� ����(����� / ���) : "; std::cin >> flight[id].getDate_from_to();
	std::cout << "������� ����� (����� / ����� : )"; std::cin >> flight[id].getTime_from_to();
	std::cout << "������� ���������� ������� : "; int ctr; std::cin >> ctr;
	flight[id].getTicket().clear();
	for (size_t i = 0; i < ctr; i++) {
		flight[id].getTicket().push_back(Ticket());
		flight[id].getTicket()[i].setSeatNumber(flight[id].seatNumberTicket);
		flight[id].seatNumberTicket++;
	}
	bool ok = true;
	std::string number;
	while (ok) {
		std::cout << "������� ����� ����� : ";
		std::cin >> number;
		for (size_t i = 0; i < flight.size(); i++) {
			if (number == flight[i].getFlightNumber()) {
				ok = false; break;
			}
		}
		if (ok = false) { ok = true; std::cout << "��������� �������" << std::endl; }
		else { ok = false; }
	}
	flight[id].setFlightNumber(number);
	std::cout << "�������� ����� �� ��������� ���� ( 1-�� , 0-��� ) : ";
	int type;
	std::cin >> type;
	flight[id].setAvailable(bool(type));
}

void Data::salesReports()
{
	std::cout << "\t\t\t***������ �� ��������***" << std::endl << std::endl;
	std::cout << "ID | Name of Pas. | Data of Pas. | Seat Num. | Price | Class Type " << std::endl << std::endl;
	for (size_t i = 0; i < flight.size(); i++) {
		for (size_t j = 0; j < flight[i].getTicket().size(); j++) {
			if (flight[i].getTicket()[j].getSold() == true) {
				std::cout << " " << j << " | "
					<< flight[i].getTicket()[j].getNameOfPassanger() << " | "
					<< flight[i].getTicket()[j].getDataOfPassanger() << " | "
					<< flight[i].getTicket()[j].getSeatNumber() << " | "
					<< flight[i].getTicket()[j].getPrice() << " | "
					<< flight[i].getTicket()[j].getClassType()
					<< std::endl;
			}
		}
	}
}

void Data::save()
{
	std::ofstream out;
	out << *this;
}

std::ofstream& operator<<(std::ofstream& fout, Data& obj)
{
	fout.open("DataBase/user.csv");
	try {

		if (!fout.is_open()) {
			throw "���� �� ��� ������";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	for (size_t i = 0; i < obj.getUser().size(); i++)
	{
		fout << obj.getUser()[i].getFullName() << ';';
		fout << obj.getUser()[i].getLogin() << ';';
		fout << obj.getUser()[i].getPassword() << ';';
		if (i < (obj.getUser().size() - 1)) { fout << obj.getUser()[i].getRights() << '\n'; }
		else { fout << obj.getUser()[i].getRights(); }
	}
	fout.close();
	fout.open("DataBase/flight.csv");
	try {
		if (!fout.is_open()) {
			throw "���� �� ��� ������";
		}
	}
	catch (const char* p) {
		std::cout << "Error : " << p << std::endl;
	}
	for (size_t i = 0; i < obj.flight.size(); i++)
	{
		if (i != 0)
		{
			fout << '\n' << obj.getFlight()[i].getAirline() << ';';
		}
		else
		{
			fout << obj.getFlight()[i].getAirline() << ';';
		}
		fout << obj.getFlight()[i].getDate_from_to() << ';';
		fout << obj.getFlight()[i].getFlightNumber() << ';';
		fout << obj.getFlight()[i].getFrom_to() << ';';
		fout << obj.getFlight()[i].getTime_from_to() << ';';
		fout << obj.getFlight()[i].getAvailable() << ';';
		fout << obj.getFlight()[i].getTicket().size() << '\n';
		for (size_t j = 0; j < obj.getFlight()[i].getTicket().size(); j++)
		{
			fout << obj.getFlight()[i].getTicket()[j].getBaggage() << ';';
			std::string chars; chars = obj.getFlight()[i].getTicket()[j].getClassType();
			fout << chars << ';';
			fout << obj.getFlight()[i].getTicket()[j].getDataOfPassanger() << ';';
			fout << obj.getFlight()[i].getTicket()[j].getNameOfPassanger() << ';';
			fout << obj.getFlight()[i].getTicket()[j].getPrice() << ';';
			if ((j < (obj.getFlight()[i].getTicket().size() - 1)))
			{
				fout << obj.getFlight()[i].getTicket()[j].getSold() << '\n';
			}
			else
			{
				fout << obj.getFlight()[i].getTicket()[j].getSold();
			}
		}
	}
	fout.close();
	return fout;
}

std::ifstream& operator>>(std::ifstream& fin, Data& obj)
{
	fin.open("DataBase/user.csv");
	char tmp[1024];
	while (!fin.eof()) {
		User user_tmp;
		fin.getline(tmp, 1024, ';');
		user_tmp.setFullName(tmp);
		fin.getline(tmp, 1024, ';');
		user_tmp.setLogin(tmp);
		fin.getline(tmp, 1024, ';');
		user_tmp.setPassword(tmp);
		fin.getline(tmp, 1024, '\n');
		user_tmp.setRights(accessRights(atoi(tmp)));
		obj.getUser().push_back(user_tmp);

	}
	fin.close();

	fin.open("DataBase/flight.csv");
	size_t j = 0;
	while (!fin.eof()) {
		Flight reys;
		fin.getline(tmp, 1024, ';');
		reys.setAirline(tmp);
		fin.getline(tmp, 1024, ';');
		reys.setDate_from_to(tmp);
		fin.getline(tmp, 1024, ';');
		reys.setFlightNumber(tmp);
		fin.getline(tmp, 1024, ';');
		reys.setFrom_to(tmp);
		fin.getline(tmp, 1024, ';');
		reys.setTime_from_to(tmp);
		fin.getline(tmp, 1024, ';');
		reys.setAvailable(bool(atoi(tmp)));
		fin.getline(tmp, 1024, '\n');
		int size = atoi(tmp);
		obj.getFlight().push_back(reys);
		for (; j < obj.getFlight().size(); j++)
		{
			for (size_t i = 0; i < size; i++) {
				Ticket ticket_tmp;
				fin.getline(tmp, 1024, ';');
				ticket_tmp.setBaggage(bool(atoi(tmp)));
				fin.getline(tmp, 1024, ';');
				ticket_tmp.setClassType(tmp[0]);
				fin.getline(tmp, 1024, ';');
				ticket_tmp.setDataOfPassanger(tmp);
				fin.getline(tmp, 1024, ';');
				ticket_tmp.setNameOfPassanger(tmp);
				fin.getline(tmp, 1024, ';');
				ticket_tmp.setPrice(atof(tmp));
				fin.getline(tmp, 1024, '\n');
				ticket_tmp.setSold(bool(atoi(tmp)));
				obj.getFlight()[j].addTicket(ticket_tmp);
			}
		}
	}
	return fin;
}