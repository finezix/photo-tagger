#include "tag.h"
#include <iostream> // to prawdopodobnie nie jest potrzebne

Tag::Tag (std::string name, unsigned int weight)
{
	this.name = name;
	this.weight = weight;
}

Tag::Tag(const Tag& other)
{
	name = other.name;
	weight = other.weight;
}

Tag& Tag::operator=(const Tag& other)
{
	name = other.name;
	weight = other.weight;
	return this;
}

friend std::ostream& Tag::operator<< ( std::ostream& os, const Tag& t )
{
	os << t.name << ": " << t.weight << ';';
}

std::string Tag::getName()
{
	return name;
}

unsigned int Tag::getWeight()
{
	return weight;
}
