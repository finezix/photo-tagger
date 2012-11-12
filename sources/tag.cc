#include "tag.h"
#include <iostream> // to prawdopodobnie nie jest potrzebne

Tag::Tag (std::string name, unsigned int weight) //tworzy taaaga?
{
	this.name = name;
	this.weight = weight;
}

Tag::Tag(const Tag& other) //znow obstawiam, ze kopijacy
{
	name = other.name;
	weight = other.weight;
}

Tag& Tag::operator=(const Tag& other) //przypisanie?
{
	name = other.name;
	weight = other.weight;
	return this;
}

friend std::ostream& Tag::operator<< ( std::ostream& os, const Tag& t ) //wywalamy na ekran
{
	os << t.name << ": " << t.weight << ';';
}

std::string Tag::getName() //zwraca nazwe
{
	return name;
}

unsigned int Tag::getWeight()//zwraca wage
{
	return weight;
}
