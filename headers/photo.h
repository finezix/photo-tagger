#define PHOTO_h
#ifndef PHOTO_h

class Photo {
public:
    Photo (std::string photoname, Date d, Taglist tags );
    friend std::ostream& operator<< ( std::ostream& os, const Photo& f );
    string getName(); // string
    Date getDate(); // Date
    int getWeight(string tagName); // int; zwraca (-1) jeœli nie ma takiego Tagu
    TagList getTagList();// TagList
    int compareTo(string); // bo mowiles, ze ka¿de T musi to mieæ…

private:
    string photoname; //nazwa zdjêcia
    Date date; // data utworzenia pliku
    TagList tags; // lista tagów przypisanych do danego zdjêcia (1-5)
};

#endif
