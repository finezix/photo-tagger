#include "photo.h"
#include "tag.h"
#include "taglist.h"
#include <iostream>

Photo::Photo (std::string photoname, const Date& d, const Taglist& tags)
{

}

friend std::ostream& Photo::operator<< ( std::ostream& os, const Photo& f )
{

}

std::string Photo::getTitle() // returns Photo's name
{

}

Date Photo::getDate() // returns Photo's Date
{

}

int Photo::getWeight(const std::string& tagName) // returns weight of tag named 'tagName', or -1 if there's no such tag
{

}

TagList Photo::getTagList()
{

}
