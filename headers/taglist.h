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
	
    bool add(const Tag& t); // dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
    int getSize(); // ilosc tagów na liscie // potrzebne?
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(const std::string& tagName); //zwraca (-1) jeœli na liœcie nie ma podanego tagu

private:
    Tag list[MAX_TAGS_COUNT]; // tablica elementow
	int size;
};

#endif // TAGLIST_H
