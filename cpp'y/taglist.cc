#include "taglist.h"
#include "tag.h"
#include <iostream>

TagList::TagList()
{

}

TagList::Tag(const TagList& other)
{

}

TagList& TagList::operator=(const TagList& other)
{

}

friend ostream& TagList::operator<<(ostream& out, const TagList& tag)
{

}

bool TagList::add(const Tag& t) // dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
{

}

int TagList::size() // iloœæ tagów na liœcie // potrzebne?
{

}
Tag TagList::get(int index) // zwraca tag spod danego indeksu
{

}

int TagList::getIndex(string tagName) //zwraca (-1) jeœli na liœcie nie ma podanego tagu
{

}

