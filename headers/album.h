#define ALBUM_h
#ifndef ALBUM_h

class Album { //album, wszystko ma w nim siedzie�
public:
    bool save(File f); // zapisywanie do pliku
    bool load(File f); // wczytywanie danych z pliku
    bool add(Photo* f); // dodawanie zdj�cia do albumu
    remove(Photo** f); //wywalanie zdj�cia z albumu
    removeAll(); // wywalanie wszystkiego, co jest w albumie, taki mega format og�lnie

private:
    Tree<Photo> photos; // drzewo zdj��
    Tree<PhotoList> tagTree; // drzewo tag�w
    Tree<PhotoList> dateTree; // drzewo dat wykonania zdj��
};

#endif
