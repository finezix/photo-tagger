#include "../headers/tag.h"
#include <iostream> // to prawdopodobnie nie jest potrzebne

Tag::Tag()
{
	name = "pusty_tag";
	weight = 1000;
}

Tag::Tag(const Tag& other) //znow obstawiam, ze kopijacy
{
	name = other.name;
	weight = other.weight;
}

Tag::Tag (std::string name, unsigned int weight) //tworzy taaaga?
{
	this->name = name;
	this->weight = weight;
}

Tag& Tag::operator=(const Tag& other) //przypisanie?
{
	name = other.name;
	weight = other.weight;
	return *this;
}

std::ostream& operator<< ( std::ostream& os, const Tag& t ) //wywalamy na ekran
//nie - wywalamy na strumien. to sie przyda, bo mozna uzyc wywalania na strumien konsoli,
//ale i wywalania na strumien pliku - zebysmy ta baze danych mieli
{
	os << t.name << ": " << t.weight << ';';
	return os;
}

std::string Tag::getName() const//zwraca nazwe
{
	return name;
}

unsigned int Tag::getWeight() const//zwraca wage
{
	return weight;
}
