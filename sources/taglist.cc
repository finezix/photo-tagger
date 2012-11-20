#include "../headers/taglist.h"
#include "../headers/tag.h"

#include <ostream>

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
	return *this;
}

std::ostream& operator<<(std::ostream& os, const TagList& tag)
{
	os << "Tags:{";
	for (int i = 0; i < tag.size; i++) {
		os << " ->" << tag.list[i];
	}
	os << '}';
	return os;
}

bool TagList::add(const Tag& t)
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

int TagList::getSize() // iloœæ tagów na liœcie //
{
	return size;
}

Tag TagList::get(int index)
{
	if (index < size) return list[index];
	else return Tag();
}

int TagList::getIndex(const std::string& tagName)
{
	int i = 0;
	bool found = false;
	while ( i < size && !found) {
		found = tagName.compare(list[i].getName()) == 0;
		i++;
	}
	return found ? i : -1;
}

