#include "../headers/photolist.h"
#include "../headers/photo.h"
#include <iostream>
//duzo czytania <3
PhotoList::PhotoList(const std::string& title)
{
	listTitle = title;
}

std::string PhotoList::getTitle() // returns List's title
{
	return listTitle;
}

int PhotoList::getSize() // returns number of held elements
{
	return size;
}

bool PhotoList::add (Photo* f) // tries to add photo, returns true if succeds
{
	//tu tez nie pamietam, jak mialo byc sortowane, data? nazwa? tagiem?
	return false;
}

Photo* PhotoList::get(int index) // returns pointer from list[index], if index >= size, NULL
{
	return index < size ? list[index] : NULL;
}
