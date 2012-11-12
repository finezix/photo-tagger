#include "taglist.h"
#include "tag.h"
#include <iostream> // tu tez pewnie niepotrzebne

TagList::TagList()
{
	size = 0;
}

TagList::TagList(const TagList& other)
{
	size = other.size;
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
}

TagList& TagList::operator=(const TagList& other)
{
	size = other.size;
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
	return this;
}

friend ostream& TagList::operator<<(ostream& out, const TagList& tag)
{
	os << "Tags:{";
	for (int i = 0; i < tag.size; i++) {
		os << ' ->' << tag.list[i];
	}
	os << '}';
	return os;
}

bool TagList::add(const Tag& t) // dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
{
	// nie pamietam, wzgledem czego zdjecie ma miec posortowane tagi? wzgledem nazwy czy wagi?
}

int TagList::size() // iloœæ tagów na liœcie // potrzebne?
{
	return size;
}

Tag TagList::get(int index) // zwraca tag spod danego indeksu
{
	if (index < size) return list[index];
	else return NULL; // chyba powinno byc inaczej, potem pomysle
}

int TagList::getIndex(const std::string& tagName) //zwraca (-1) jeœli na liœcie nie ma podanego tagu
{
	int i = 0;
	bool found = false;
	while ( i < size && !found) {
		found = tagName.compare(list[i].getName()) == 0;
	}
	return found ? i : -1;
}

