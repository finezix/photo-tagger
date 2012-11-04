#define PHOTOLIST_h
#ifndef PHOTOLIST_h

class PhotoList {
public:
    bool add (Photo* f); // dodaje zdjêcie, zwraca true gdy dodano
    int size(); // iloœæ zdjêæ
    Foto* get(int index); // zwraca zdjêcie spod indeksu
    string getTitle();
    int compareTo(string); // ka¿de T musi to mieæ…

private:
    int Photo* list [MAX_PHOTOS_COUNT]; // rozmiar
};

#endif
