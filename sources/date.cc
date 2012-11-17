#include "../headers/date.h"

#include <sstream>

Date::Date (unsigned int dd, unsigned int mm, unsigned int yyyy) //on nam po prostu tworzy datke, prawda...?
{
	this->dd = dd;
	this->mm = mm;
	this->yyyy = yyyy;
}

Date::Date (const Date& other) // kopijacy...? lol, znow nic nie wiem. :D
{
	dd = other.dd;
	mm = other.mm;
	yyyy = other.yyyy;
}

Date& Date::operator=(const Date& other) //operator przypisania tak zwany?
{
	dd = other.dd;
	mm = other.mm;
	yyyy = other.yyyy;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Date& d) // strumieniowy, wypisuje na ekran
{
	os << d.dd << '.' << d.mm << '.' << d.yyyy;
	return os;
}

int Date::compareTo(const Date& d) //int //porownuje daty, nie?
{
	return (dd + mm * 31 + yyyy * 366) - (d.dd + d.mm * 31 + d.yyyy * 366);
}

std::string Date::toString() // string a ten mial robic stringa z daty <3 ale nie pamietam po jaka cholercie...
{
	std::ostringstream ss;
	ss << "Data: " << dd << '.' << mm << '.' << yyyy << ';';
	return ss.str();
}

