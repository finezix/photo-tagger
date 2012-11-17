#ifndef TAGLIST_H
#define TAGLIST_H

#define MAX_TAGS_COUNT 5

#include "tag.h"

#include <ostream>
#include <string>

class TagList
{
public:
	TagList();
	TagList(const TagList& other);
	TagList& operator=(const TagList& other);
	friend std::ostream& operator<<(std::ostream& out, const TagList& tag);
	
    bool add(const Tag& t); // dodaje tag, zwraca true  je�li tagu wcze�niej nie by�o na li�cie i zosta� poprawnie dodany
    int getSize(); // ilosc tag�w na liscie // potrzebne?
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(const std::string& tagName); //zwraca (-1) je�li na li�cie nie ma podanego tagu

private:
    Tag list[MAX_TAGS_COUNT]; // tablica elementow
	int size;
};

#endif // TAGLIST_H
