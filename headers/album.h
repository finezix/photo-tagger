#ifndef ALBUM_H
#define ALBUM_H

#include "photo.h"
#include "tree.h"
#include "photolist.h"

#include <ostream>

class Album
{ //album, wszystko ma w nim siedziec
public:
	~Album();
    bool save(); // zapisywanie do pliku
    bool load(); // wczytywanie danych z pliku
    bool add(Photo* p); // dodawanie zdjecia do albumu
    void remove(Photo* p); //wywalanie zdjecia z albumu
    void removeAll(); // wywalanie wszystkiego, co jest w albumie, taki mega format ogolnie
	friend std::ostream& operator<<(std::ostream& out, const Album& album);
	Tree<PhotoList> tagTree; // drzewo tagow
	
private:
    Tree<Photo> photos; // drzewo zdjec
    
    Tree<PhotoList> dateTree; // drzewo dat wykonania zdjec
};

#endif // ALBUM_H
