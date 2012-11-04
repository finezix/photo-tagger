#define PHOTO_h
#ifndef PHOTO_h

class Photo {
public:
    Photo (std::string photoname, Date d, Taglist tags );
    friend std::ostream& operator<< ( std::ostream& os, const Photo& f );
    string getName(); // string
    Date getDate(); // Date
    int getWeight(string tagName); // int; zwraca (-1) je�li nie ma takiego Tagu
    TagList getTagList();// TagList
    int compareTo(string); // bo mowiles, ze ka�de T musi to mie�

private:
    string photoname; //nazwa zdj�cia
    Date date; // data utworzenia pliku
    TagList tags; // lista tag�w przypisanych do danego zdj�cia (1-5)
};

#endif
