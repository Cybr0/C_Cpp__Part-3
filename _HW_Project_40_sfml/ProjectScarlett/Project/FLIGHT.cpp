#include "FLIGHT.h"

Ticket::Ticket() : Ticket("nameOfPassanger", "dataOfPassanger", 'X', 0, false, 5.5, false)
{
}

Ticket::Ticket(std::string nameOfPassanger, std::string dataOfPassanger, char classType, int seatNumber, bool baggage, double price, bool sold)
{
	this->nameOfPassanger = nameOfPassanger;
	this->dataOfPassanger = dataOfPassanger;
	this->classType = classType;
	this->seatNumber = seatNumber;
	this->baggage = baggage;
	this->price = price;
	this->sold = sold;
}

Ticket::~Ticket()
{
}

std::string& Ticket::getNameOfPassanger()
{
	return nameOfPassanger;
}

std::string& Ticket::getDataOfPassanger()
{
	return dataOfPassanger;
}

char& Ticket::getClassType()
{
	return classType;
}

bool& Ticket::getBaggage()
{
	return baggage;
}

double& Ticket::getPrice()
{
	return price;
}

bool& Ticket::getSold()
{
	return sold;
}

void Ticket::setNameOfPassanger(std::string nameOfPassanger)
{
	this->nameOfPassanger = nameOfPassanger;
}

void Ticket::setDataOfPassanger(std::string dataOfPassanger)
{
	this->dataOfPassanger = dataOfPassanger;
}

void Ticket::setClassType(char classType)
{
	this->classType = classType;
}

void Ticket::setBaggage(bool baggage)
{
	this->baggage = baggage;
}

void Ticket::setPrice(double price)
{
	this->price = price;
}

void Ticket::setSold(bool sold)
{
	this->sold = sold;
}

Flight::Flight() : Flight("AIRLINE", "FlightNumber", "ORIGIN/DESTINATION",
	"01.01.2019/01.01.2019", "00:00/00:00", ticket, true)
{
}

Flight::Flight(std::vector<Ticket> ticket) : Flight()
{
	this->ticket = ticket;
}

Flight::Flight(std::string airline, std::string flightNumber, std::string from_to,
	std::string date_from_to, std::string time_from_to,
	std::vector<Ticket> ticket, bool available)
{
	this->airline = airline;
	this->flightNumber = flightNumber;
	this->from_to = from_to;
	this->date_from_to = date_from_to;
	this->time_from_to = time_from_to;
	this->ticket = ticket;
	this->available = available;
}

Flight::~Flight()
{
}


std::string& Flight::getAirline()
{
	// TODO: вставьте здесь оператор return
	return airline;
}

std::string& Flight::getFlightNumber()
{
	return flightNumber;
}

std::string& Flight::getFrom_to()
{
	return from_to;
}

std::string& Flight::getDate_from_to()
{
	return date_from_to;
}

std::string& Flight::getTime_from_to()
{
	return time_from_to;
}

std::vector<Ticket>& Flight::getTicket()
{
	return ticket;
}

void Flight::addTicket(Ticket& t)
{
	ticket.push_back(t);
	//countTicket++;
}

//void Flight::setCountTicket(int countTicket) {
//	this->countTicket = countTicket;
//}

void Flight::setAirline(std::string airline)
{
	this->airline = airline;
}

void Flight::setFlightNumber(std::string flightNumber)
{
	this->flightNumber = flightNumber;
}

void Flight::setFrom_to(std::string from_to)
{
	this->from_to = from_to;
}

void Flight::setDate_from_to(std::string date_from_to)
{
	this->date_from_to = date_from_to;
}

void Flight::setTime_from_to(std::string time_from_to)
{
	this->time_from_to = time_from_to;
}

void Flight::setTicket(std::vector<Ticket> ticket)
{
	this->ticket = ticket;
}
