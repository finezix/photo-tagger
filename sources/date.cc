#include "date.h"
#include <iostream> // nie jestem pewien czy to bedzie potrzebne //tez nie wiem, ale zawsze sie wstawia...

Date::Date (unsigned int dd, unsigned int mm, unsigned int yyyy) //on nam po prostu tworzy datke, prawda...?
{
	this.dd = dd;
	this.mm = mm;
	this.yyyy = yyyy;
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
	return this;
}

friend std::ostream& operator<< ( std::ostream& os, const Date& d ) // strumieniowy, wypisuje na ekran
{
	os << d.dd << '.' << d.mm << '.' << d.yyyy;
	return os;
}

int Date::compareTo(const Date& d) //int //porownuje daty, nie?
{
	return (dd + mm * 30 + yyyy * 365) - (d.dd + d.mm * 30 + d.yyyy * 365);
}

string Date::toString() // string a ten mial robic stringa z daty <3 ale nie pamietam po jaka cholercie...
{

}

