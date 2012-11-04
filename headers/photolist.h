#define PHOTOLIST_h
#ifndef PHOTOLIST_h

class PhotoList {
public:
    bool add (Photo* f); // dodaje zdj�cie, zwraca true gdy dodano
    int size(); // ilo�� zdj��
    Foto* get(int index); // zwraca zdj�cie spod indeksu
    string getTitle();
    int compareTo(string); // ka�de T musi to mie�

private:
    int Photo* list [MAX_PHOTOS_COUNT]; // rozmiar
};

#endif
