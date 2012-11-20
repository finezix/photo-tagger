#include "../headers/photolist.h"
#include "../headers/photo.h"
#include <iostream>

PhotoList::PhotoList(const std::string& title)
{
	listTitle = title;
}

std::ostream& operator<<(std::ostream& out, PhotoList* list) {
	out << "Tytuł: " << list->listTitle << std::endl;
	for (int i = 0; i < list->size; i++)
		out << *(list->list[i]);
	return out;
}

std::string PhotoList::getTitle() // returns List's title
{
	return listTitle;
}

int PhotoList::getSize() // returns number of held elements
{
	return size;
}

bool PhotoList::add (Photo* p) // tries to add photo, returns true if succeds
{
	if (size + 1 > MAX_PHOTOS_COUNT)
		return false;
	int i = 0;
	// znajdowanie indeksu pod ktory trzeba wstawic
	if (p->getWeight(listTitle) < 0)
		while (i < size && list[i]->getTitle() <= p->getTitle())
			i++;
	else
		while (i < size && list[i]->getWeight(listTitle) <= p->getWeight(listTitle))
			i++;
	if (i == size) {
		list[size++] = p;
	} else {
		int j = i;
		Photo* dummy = list[j++];
		while (j < size) {
			Photo* dummy2 = list[j];
			list[j] = dummy;
			dummy = dummy2;
			j++;
		}
		list[size++] = dummy;
		list[i] = p;
	}
	return true;
}

Photo* PhotoList::get(int index) // zwraca wskaznik do list[index], jesli index >= size, zwraca NULL
{
	return index < size ? list[index] : NULL;
}
