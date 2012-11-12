#include "photolist.h"
#include "photo.h"
#include <iostream> // pewnie niepotrzebne

PhotoList::PhotoList(const std::string& title)
{
	listTitle = title;
}

std::string PhotoList::getTitle() // returns List's title
{
	return listTitle;
}

int PhotoList::size() // returns number of held elements
{
	return size;
}

bool PhotoList::add (Photo* f) // tries to add photo, returns true if succeds
{
	//tu tez nie pamietam, jak mialo byc sortowane, data? nazwa? tagiem?
}

Foto* PhotoList::get(int index) // returns pointer from list[index], if index >= size, NULL
{
	return index < size ? list[index] : NULL;
}
