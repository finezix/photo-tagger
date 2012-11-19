#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <ostream>
#include <string>


template <class T>
class Tree
{
public:
    Tree();
    Tree(const Tree<T>& other);
    Tree<T>& operator=(const Tree<T>& other);
    template <class U> friend std::ostream& operator<<(std::ostream& out, const Tree<U>& tree);
    int count();
    bool add(T* object);
    bool remove(const std::string& title);
    void clear();
    void seekAndDestroy();
    T* find(const std::string& title);

private:
    Node<T>* root;
    int count(Node<T>* node);
    bool addT(Node<T>* node, T* object);
	Node<T>* remove(Node<T>* wanted, Node<T>* current);
    void clear(Node<T>* node);
    void seekAndDestroy(Node<T>* node);
    Node<T>* findNode(Node<T>* node, const std::string& title);
};



// definitions

template <class T>
Tree<T>::Tree()
{
    root = NULL;
}

template <class T>
Tree<T>::Tree(const Tree<T>& other)
{
    root = other.root;
}

template <class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other)
{
    if (root != other.root) {
        clear();
        root = other.root;
    }
    return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Tree<T>& tree)
{
    if (tree.root != NULL) {
        out << tree.root;
    }
    return out;
}

template <class T>
int Tree<T>::count()
{
    return count(root);
}

template <class T>
bool Tree<T>::add(T* object)
{
    if (object == NULL) {return false;}
    if (root == NULL) {
        root = new Node<T>(object);
        return true;
    }
    return add(root, object);
}

template <class T>
bool Tree<T>::remove(const std::string& title)
{
    Node<T>* node = findNode(root, title);
    if (node == NULL) {
        return false;
    }
    root = remove(node, root);
    return true;
}

template <class T>
void Tree<T>::clear()
{
    if (root != NULL) {
        clear(root);
        root = NULL;
    }
}

template <class T>
void Tree<T>::seekAndDestroy()
{
    if (root != NULL) {
        seekAndDestroy(root);
        root = NULL;
    }
}

template <class T>
T* Tree<T>::find(const std::string& title)
{
    Node<T>* node = findNode(root, title);
    if (node == NULL) {
        return NULL;
    }
    return node->value;
}

/*
 * <<<<<<<<<<<<<<<
 * private
 * <<<<<<<<<<<<<<<
 */

template <class T>
int Tree<T>::count(Node<T>* node)
{
    if (node == NULL) { return 0;}
    return 1 + count(node->left) + count(node->right);
}

template <class T>
bool Tree<T>::addT(Node<T>* node, T* object)
{
    int comparisonResult = object->getTitle().compare(node->value->getTitle());
    if (comparisonResult < 0) {
        if (node->left != NULL) {
            return addT(node->left, object);
        } else {
            node->left = new Node<T>(object);
            return true;
        }
    } else if (comparisonResult > 0) {
          if (node->right != NULL) {
            return addT(node->right, object);
        } else {
            node->right = new Node<T>(object);
            return true;
        }
    }
    return false;
}

template <class T>
Node<T>* Tree<T>::remove(Node<T>* wanted, Node<T>* current)
{
    if (current != wanted) {
        current->left = remove(current->left);
        current->right = remove(current->right);
    } else {
        if (current->left == NULL && current->right == NULL) {
            delete wanted;
            current = NULL;
        } else if (current->left == NULL || current->right == NULL) {
            current = current->left == NULL ? current->right : current->left;
            delete wanted;
            return current;
        } else {
            int leftSize = count(current->left);
            int rightSize = count(current->right);
            if (leftSize < rightSize) {
                current->value = current->right->value;
                current->right = remove(current->right, current->right);
            } else {
                current->value = current->left->value;
                current->left = remove(current->left, current->left);
            }
        }
    }
    return current;
}

template <class T>
void Tree<T>::clear(Node<T>* node)
{
    if (node->left != NULL) {clear(node->left);}
    if (node->right != NULL) {clear(node->right);}
    delete node;
}

template <class T>
void Tree<T>::seekAndDestroy(Node<T>* node)
{
    if (node->left != NULL) {seekAndDestroy(node->left);}
    if (node->right != NULL) {seekAndDestroy(node->right);}
    delete node->value;
    delete node;
}

template <class T>
Node<T>* Tree<T>::findNode(Node<T>* node, const std::string& title)
{
    if (node == NULL) {
        return NULL;
    }
    int comparisonResult = title.compare(node->value->getTitle());
    if (comparisonResult == 0) {
        return node;
    }
    if (comparisonResult < 0) {
        return findNode(node->left, title);
    } else {
        return findNode(node->right, title);
    }
}

#endif // TREE_H
