#include "../headers/photo.h"
#include "../headers/tag.h"
#include "../headers/taglist.h"
#include <iostream>

Photo::Photo (std::string title, const Date& d, const TagList& t)
: photoName(title), date(d), tags(t)
{
    photoName = title;
}

std::ostream& operator<< (std::ostream& os, const Photo& f ) //wypisuje wszystko, co wiemy o zdjecia
{
	os << f.photoName << ", " << f.date << ", " << f.tags << std::endl;
	return os;
}

std::string Photo::getTitle() // returns Photo's name
{
	return photoName;
}

Date Photo::getDate() // returns Photo's Date
{
	return date;
}

int Photo::getWeight(const std::string& tagName) // returns weight of tag named 'tagName', or -1 if there's no such tag
{
	int index = tags.getIndex(tagName);
	return index == -1 ? -1 : tags.get(index).getWeight();
}

TagList Photo::getTagList()
{
	return tags;
}
