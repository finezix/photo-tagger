#define ALBUM_h
#ifndef ALBUM_h

class Album { //album, wszystko ma w nim siedzieæ
public:
    bool save(File f); // zapisywanie do pliku
    bool load(File f); // wczytywanie danych z pliku
    bool add(Photo* f); // dodawanie zdjêcia do albumu
    remove(Photo** f); //wywalanie zdjêcia z albumu
    removeAll(); // wywalanie wszystkiego, co jest w albumie, taki mega format ogólnie

private:
    Tree<Photo> photos; // drzewo zdjêæ
    Tree<PhotoList> tagTree; // drzewo tagów
    Tree<PhotoList> dateTree; // drzewo dat wykonania zdjêæ
};

#endif
