#ifndef PHOTO_H
#define PHOTO_H

#include "date.h"
#include "taglist.h"

#include <ostream>
#include <string>

class Photo
{
public:
    Photo (std::string title, const Date& d, const TagList& t);
    friend std::ostream& operator<< (std::ostream& os, const Photo& f);
	
    std::string getTitle(); // returns Photo's name
    Date getDate(); // returns Photo's Date
    int getWeight(const std::string& tagName);// returns weight of tag named 'tagName', or -1 if there's no such tag
    TagList getTagList();// returns Photo's TagList

private:
    std::string photoName;
    Date date; // Photo's shooting date
    TagList tags; // list of tags connected with this Photo with their weights (1-5)
};

#endif // PHOTO_H