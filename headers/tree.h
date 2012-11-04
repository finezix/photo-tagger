#define TREE_h
#ifndef TREE_h

template <class T>

class Tree { // drzewo

public:
    int count(); // to chyba miala byc ilosc elementow, nie?
    bool add(T object); // dodaje objekt do drzewa
    bool remove(T object); // usuwa objekt z drzewa
    T* find(string Title); // wyszukiwanie wêz³a po nazwie
    int compareTo(string); // ka¿de T musi to mieæ…

private:
    Node<T> root; // korzeñ
    T* findT(Node <T> x); // funkcja pomocnicza wyszukiwania
};


#endif
