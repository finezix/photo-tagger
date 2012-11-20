#include "../headers/date.h"

#include <sstream>

Date::Date (unsigned int dd, unsigned int mm, unsigned int yyyy)
{
	this->dd = dd;
	this->mm = mm;
	this->yyyy = yyyy;
}

Date::Date (const Date& other)
{
	dd = other.dd;
	mm = other.mm;
	yyyy = other.yyyy;
}

Date& Date::operator=(const Date& other)
{
	dd = other.dd;
	mm = other.mm;
	yyyy = other.yyyy;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Date& d)
{
	os << d.dd << '.' << d.mm << '.' << d.yyyy;
	return os;
}

int Date::compareTo(const Date& d)
{
	return (dd + mm * 31 + yyyy * 366) - (d.dd + d.mm * 31 + d.yyyy * 366);
}

std::string Date::toString()
{
	std::ostringstream ss;
	ss << "Data: " << dd << '.' << mm << '.' << yyyy << ';';
	return ss.str();
}

