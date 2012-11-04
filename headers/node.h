#define NODE_h
#ifndef NODE_h

template <class T> // deklaracja ¿e to klasa-wzornik, z parametrem T, który musi byæ klas¹
class Node { 

public:
    Node (T* value) {
        this->value = value; // inicjalizujê wskaŸnik wartoœci
        left = right = NULL; // podczas tworzenia nowego wêz³a jest on liœciem - nie ma synów
    };
    
    T* value; // wskaŸnik na wartoœæ wêz³a
    
    Node<T> * left, * right; // wskaŸniki do lewego i prawego syna
};


#endif
