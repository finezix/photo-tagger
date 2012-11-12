#define TAGLIST_h
#ifndef TAGLIST_h

class TagList {
public:
	TagList();
	TagList(const TagList& other);
	TagList& operator=(const TagList& other);
	friend ostream& operator<<(ostream& out, const TagList& tag);
	
    bool add(const Tag& t); // dodaje tag, zwraca true  je�li tagu wcze�niej nie by�o na li�cie i zosta� poprawnie dodany
    int size(); // ilo�� tag�w na li�cie // potrzebne?
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(const std::string& tagName); //zwraca (-1) je�li na li�cie nie ma podanego tagu

private:
    Tag list[MAX_TAGS_COUNT]; // tablica elementow
	int size;
};

#endif
