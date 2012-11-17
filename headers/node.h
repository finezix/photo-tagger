#ifndef NODE_H
#define NODE_H

#include <ostream>

template <class T>
// declaration it's template-class with parameter T which has to be class

class Node {

public:
    Node<T> (T* value) {
        this->value = value;
        // initializing value pointer
        left = right = NULL;
        // when creating new node, it doesn't have children
    };

    T* value; // pointer to node's value

    Node<T> * left, * right; // left and right sons pointers

    friend std::ostream& operator<< (std::ostream& out, const Node<T>& node)
    {
        if (node.left != NULL) {
            out << *(node.left);//writes left subtree to stream
        }
        out << *(node.value) << std::endl;//writes value to stream - value itself has to know how
        if (node.right != NULL) {
            out << *(node.right);//writes right subtree to stream
        }
        return out;
    };
};

#endif // NODE_H