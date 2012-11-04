#define NODE_h
#ifndef NODE_h

template <class T> // deklaracja �e to klasa-wzornik, z parametrem T, kt�ry musi by� klas�
class Node { 

public:
    Node (T* value) {
        this->value = value; // inicjalizuj� wska�nik warto�ci
        left = right = NULL; // podczas tworzenia nowego w�z�a jest on li�ciem - nie ma syn�w
    };
    
    T* value; // wska�nik na warto�� w�z�a
    
    Node<T> * left, * right; // wska�niki do lewego i prawego syna
};


#endif
