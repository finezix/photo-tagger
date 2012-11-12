#include "date.h"
#include <iostream> // nie jestem pewien czy to bedzie potrzebne

Date::Date (unsigned int dd, unsigned int mm, unsigned int yyyy)
{
	this.dd = dd;
	this.mm = mm;
	this.yyyy = yyyy;
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
	return this;
}

friend std::ostream& operator<< ( std::ostream& os, const Date& d )
{
	os << d.dd << '.' << d.mm << '.' << d.yyyy;
	return os;
}

int Date::compareTo(const Date& d) //int
{
	return (dd + mm * 30 + yyyy * 365) - (d.dd + d.mm * 30 + d.yyyy * 365);
}

string Date::toString() // string
{

}

