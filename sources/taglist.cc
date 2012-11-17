#include "../headers/taglist.h"
#include "../headers/tag.h"

#include <ostream> // tu tez pewnie niepotrzebne //pewnie nie

TagList::TagList()//pusty, nic z nim nie zrobimy...?
// ustawiamy size na 0, to dosc wazne
{
	size = 0;
}

TagList::TagList(const TagList& other) //
{
	size = other.size;
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
}

TagList& TagList::operator=(const TagList& other) // czy to serio kopiuje...?
{
	size = other.size;
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const TagList& tag) //wypisuje... lol. nie wiem.
{
	os << "Tags:{";
	for (int i = 0; i < tag.size; i++) {
		os << " ->" << tag.list[i];
	}
	os << '}';
	return os;
}

bool TagList::add(const Tag& t) // dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
{
	if (size + 1 > MAX_TAGS_COUNT)
		return false;
	int i = 0;
	while (i < size && list[i].getWeight() <= t.getWeight())
		i++;
	if (i == size) {
		list[size++] = t;
	} else {
		int j = i;
		Tag dummy = list[j++];
		while (j < size) {
			Tag dummy2 = list[j];
			list[j] = dummy;
			dummy = dummy2;
			j++;
		}
		list[size++] = dummy;
		list[i] = t;
	}
	return true;
}

int TagList::getSize() // iloœæ tagów na liœcie // potrzebne? // chyba tak
{
	return size;
}

Tag TagList::get(int index) // zwraca tag spod danego indeksu
{
	if (index < size) return list[index];
	else return Tag(); // chyba powinno byc inaczej, potem pomysle // anie lepiej, zeby wypisalo "brak tagusia"czy cos takiego?
}

int TagList::getIndex(const std::string& tagName) //zwraca (-1) jeœli na liœcie nie ma podanego tagu // tak, to rozumieeem
{
	int i = 0;
	bool found = false;
	while ( i < size && !found) {
		found = tagName.compare(list[i].getName()) == 0;
		i++;
	}
	return found ? i : -1;
}

