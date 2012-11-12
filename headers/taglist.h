#define TAGLIST_h
#ifndef TAGLIST_h

class TagList {
public:
	TagList();
	TagList(const TagList& other);
	TagList& operator=(const TagList& other);
	friend ostream& operator<<(ostream& out, const TagList& tag);
	
    bool add(const Tag& t); // dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
    int size(); // iloœæ tagów na liœcie // potrzebne?
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(const std::string& tagName); //zwraca (-1) jeœli na liœcie nie ma podanego tagu

private:
    Tag list[MAX_TAGS_COUNT]; // tablica elementow
	int size;
};

#endif
