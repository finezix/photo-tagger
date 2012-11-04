#define TAGLIST_h
#ifndef TAGLIST_h

class TagList {
public:
    bool add(Tag t); // bool; dodaje tag, zwraca true  je�li tagu wcze�niej nie by�o na li�cie i zosta� poprawnie dodany
    int size(); // int; ilo�� tag�w na li�cie
    Tag get(int index); // zwraca tag spod danego indeksu
    int getIndex(string tagName); //zwraca (-1) je�li na li�cie nie ma podanego tagu

private:
    int Tag* list[MAX_TAGS_COUNT]; // rozmiar
};

#endif
