#include "../headers/photo.h"
#include "../headers/tag.h"
#include "../headers/taglist.h"
#include <iostream> // niepotrzebne chyba

Photo::Photo (std::string title, const Date& d, const TagList& t)
: photoName(title), date(d), tags(t)
//tworzy fote :D (czyli te aparaty przereklamowane sa)
{
    photoName = title;
}

std::ostream& operator<< (std::ostream& os, const Photo& f ) //wypisuje wszystko, co wiemy o focie
{
	os << f.photoName << ", " << f.date << ", " << f.tags << std::endl;
	return os;
}

std::string Photo::getTitle() // returns Photo's name//tak
{
	return photoName;
}

Date Photo::getDate() // returns Photo's Date//tak
{
	return date;
}

int Photo::getWeight(const std::string& tagName) // returns weight of tag named 'tagName', or -1 if there's no such tag
{
	int index = tags.getIndex(tagName);
	return index == -1 ? -1 : tags.get(index).getWeight();
}

TagList Photo::getTagList()//lol! to dzialac bedzie...? O.o
{
	return tags;
}
