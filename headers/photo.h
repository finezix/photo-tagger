#define PHOTO_h
#ifndef PHOTO_h

class Photo {
public:
    Photo (std::string photoname, const Date& d, const Taglist& tags);
    friend std::ostream& operator<< ( std::ostream& os, const Photo& f );
	
    std::string getTitle(); // returns Photo's name
    Date getDate(); // returns Photo's Date
    int getWeight(const std::string& tagName);// returns weight of tag named 'tagName', or -1 if there's no such tag
    TagList getTagList();// returns Photo's TagList

private:
    string photoName;
    Date date; // Photo's shooting date
    TagList tags; // list of tags connected with this Photo with their weights (1-5)
};

#endif
