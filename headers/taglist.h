#define TAGLIST_h
#ifndef TAGLIST_h

class TagList {
public:
    bool add(Tag t); // bool; dodaje tag, zwraca true  jeœli tagu wczeœniej nie by³o na liœcie i zosta³ poprawnie dodany
    int size(); // int; iloœæ tagów na liœcie
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(string tagName); //zwraca (-1) jeœli na liœcie nie ma podanego tagu

private:
    int Tag* list[MAX_TAGS_COUNT]; // rozmiar
};

#endif
