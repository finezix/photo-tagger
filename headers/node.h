
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

    friend ostream& operator<< (ostream& out, const Node<T>& node)
    {
        if (left != NULL) {
            out << *left;//writes left subtree to stream
        }
        out << *value << endl;//writes value to stream - value itself has to know how
        if (right != NULL) {
            out << *right;//writes right subtree to stream
        }
    };
};

