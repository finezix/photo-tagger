/*
 * class T has to implement single method:
 * std::string& getTitle();
 *
 * the tree operates using titles of held objects
 */

template <class T>
class Tree
{
public:
    Tree();

    Tree(const Tree<T>& other);

    Tree<T>& operator=(const Tree<T>& other);

    friend ostream& operator<<(ostream& out, const Tree<T>& tree);//strumieniowy, wypisywanie, co nie?
    //zgadza sie

    int count(); //licznik?
    //funkcja liczaca raczej, chyba ze to mialas na mysli

    /* searches for T* pointer such that
    pointer == object,
    and if such pointer is found returns false,
    otherwise adds object to the tree and returns true */ //kk.
    bool add(T* object);

    /* searches for T* pointer such that
    pointer->getTitle().compare(title) == 0,
    and if such pointer is found removes it (only pointer, not object)
    and returns true, otherwise returns false */
    bool remove(const std::string& title);

    /* deletes nodes, but doesn't touch pointers held by them */   //tego nie lapie.
    // usuwa wezly, ale nie robi 'delete value', czyli nie niszczy danych, za to zwalnia
    // pamiec zajeta przez samo drzewo. potrzebne, poniewaz gdy bedziemy mieli dwa drzewa
    // ze wskaznikami do zdjec, jedno posortowane data, drugie posortowane nazwa,
    // to bez tej funkcji po usunieciu pierwszego wywalilby nam sie program podczas
    // usuwania drugiego, bo chcialoby usuwac wartosci, ktore nie istnieja - pytania?
    void clear();

    /* deletes objects pointed by nodes and all nodes themselves */
    void seekAndDestroy();  //nazwa to mnie zwalila z nog... ty takie zapedy masz, serio...?
    // akurat sluchalem tego utworu, i uznalem tytul za dobrze wyjasniajacy efekt dzialania

    /* searches for T* pointer such that
    object->getTitle().compare(title) == 0, and if such pointer is found,
    returns it, otherwise returns NULL */
    T* find(const std::string& title);

private:
    Node<T>* root;

    int count(Node<T>* node);

    bool addT(Node<T>* node, T* object);

    bool remove(Node<T>* node);

    void clear(Node<T>* node);

    void seekAndDestroy(Node<T>* node);

    Node<T>* findNode(Node<T>* node, const std::string& title);
};



// definitions

template <class T>
Tree<T>::Tree() //to ten konstruktor taki, co i tak sie nic z nim nie zrobi potem?
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
friend ostream& Tree<T>::operator<<(ostream& out, const Tree<T>& tree); //moj ulubiony strumieniowy?
{
    if (tree.root != NULL) {
        out << tree.root;
    }
    return out;
}

/* counts number of nodes in tree */  //nie, nie wiem, co tu robi root i co to jest.
template <class T>
int Tree<T>::count()
{
    return count(root);
}

/* searches for T* pointer such that
pointer == object,
and if such pointer is found returns false,
otherwise adds object to the tree and returns true */
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

/* searches for T* pointer such that
pointer->getTitle().compare(title) == 0,
and if such pointer is found removes it (only pointer, not object)
and returns true, otherwise returns false */
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

/* deletes nodes, but doesn't touch pointers held by them */
template <class T>
void Tree<T>::clear()
{
    if (root != NULL) {
        clear(root);
        root = NULL;  //a tu nie powinien byc root? bo oot'a nie bylo do tej pory... no nic, poprawiam :P
        // no dzieki za poprawke, zgubilem, fakt
    }
}

/* deletes objects pointed by nodes and all nodes themselves */
template <class T>
void Tree<T>::seekAndDestroy()
{
    if (root != NULL) {
        seekAndDestroy(root);
        root = NULL;
    }
}

/* searches for T* pointer such that
object->getTitle().compare(title) == 0, and if such pointer is found,
returns it, otherwise returns NULL */
template <class T>
T* Tree<T>::find(const std::string& title)
{
    Node<T>* node = findNode(root, title);
    if (node == NULL) {
        return NULL;
    }
    return node->value;
}

template <class T>
int Tree<T>::count(Node<T>* node)  //a czeeemu taaak?
// to jest funkcja pomocnicza dla funkcji publicznej. zwraca liczbe
// elementow zawartych w poddrzewie. jak widzisz wywoluje sie rekurencyjnie
// dzieki czemu kazdy wezel zwraca po prostu sume z poddrzew zwiekszona o jeden.
// lisc zwraca 1, bo jego NULL-synowie zwroca zero, ojciec dwoch takich lisci
// zwroci trzy, bo od synow dostanie 1+1, i sam doda jeden. pytania?
{
    if (node == NULL) { return 0;}
    return 1 + count(node->left) + count(node->right);
}

template <class T>
bool Tree<T>::addT(Node<T>* node, T* object)
{
    int comparisonResult = object->getTitle().compare(node->value->getTitle());
    if (comparisonResult < 0) {
        //object is lesser than the one in node
        if (node->left != NULL) {
            return addT(node->left, object); // adding to left subtree
        } else {
            node->left = new Node<T>(object); // creating left subtree
            return true; // object added  // to ideowo weszlo do zakutej bani mojej :D
            // to znaczy rozumiem, ze cale dodawanie ogarniasz, tak?
        }
    } else if (comparisonResult > 0) {
        //object is greater than the one in node
        if (node->right != NULL) {
            return addT(node->right, object); // adding to right subtree
        } else {
            node->right = new Node<T>(object); // creating right subtree
            return true; // object added
        }
    }
    // object already in tree
    return false;
}

/* removes 'wanted' from 'current' tree by checking if current is wanted,
 * if not: calls remove on both children and assigns results to them
 * if yes, checks:
 *  - if node has no children, deletes and returns NULL
 *  - if node has one child, deletes and returns child
 *  - if node has two childs, checks which has greater size;
 *      then assigns to current the value of greater child and calls to remove it
 */

template <class T>
Node<T>* Tree<T>::remove(Node<T>* wanted, Node<T>* current)
{
    if (current != wanted) {
        current->left = remove(current->left);
        current->right = remove(current->right);
    } else {
        if (current->left == NULL && node->right == NULL) {
            // node is leaf, we just delete it
            delete wanted;
            current = NULL;
        } else if (current->left == NULL || node->right == NULL) {
            // node has one child
            current = current->left == NULL ? current->right : current->left; // nie wiem, jak to dziala, ale sie dowiem. to pewnie jakis skrot zapisowy genialny...?
            // tak. na current przypisujesz current->right lub current->left w zaleznosci od tego, czy
            // current->left == null. taki if, ktory zwraca jakas wartosc:
            // current = (if) c->l == null (? = then) c->r (: = else) c->l; dalsze pytania?
            delete wanted;
            return current;
        } else {
            // node has two childs, check size of both
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
//mogliby mi grozic wymordowaniem calej rodziny (takim wymordowaniem z uzyciem starej skarpetki) a i tak bym nie urodzila takiej bestii O.o
// spoko. jak chcesz sie wiecej dowiedziec, skad to cudo: http://en.wikipedia.org/wiki/Binary_search_tree#Deletion
// ta funkcja, jak widzisz, zwraca wskaznik do obecnie przerabianego wezla.
// chodzi o to, zeby u rodzica w razie potrzeby zmienic syna z tego (current) na innego
// albo chocby zmienic u rodzica wskaznik na NULL, jesli usuniemy current,
// tak jak tam gdzie jest 'node is leaf'. to nie jest takie oczywiste,
// ale jak moment pomyslisz, i przeczytasz to wiki, to powinnas zrozumiec.
// to ostatnie, 'check size', jest opcjonalne. moglbym wpisac po prostu ktoras
// pare linijek, ale jesli dam ifa, to zmniejsze o jeden wezel to wieksze poddrzewo.
// taka najprostsza optymalizacja.

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
        //object found
        return node;
    }
    if (comparisonResult < 0) {
        // object lesser than the one in node, searching left subtree
        return findNode(node->left, title);
    } else {
        // object greater than the one in node, searching right subtree
        return findNode(node->right, title);
    }
}

// LOL1: serio? angielski? do mnie? O.o
//LOL2: ile tego jest?!?!?!
//wiec ogolnie: nie ogarniam root'a. a pewnie powinnam.
//--------->rozumiem, ze juz ogarniasz po konsultacji na skype
//i skad ty wiesz, jak to powinno byc? tzn. jak czytam, to widze, ze to, co mniejwiecej rozumiem ma szanse dzialac.
//ale skad to wiedziec? O.o
//---------> sluchaj, ja juz to raz pisalem, tyle ze w Pascalu.
// mam to ogolnie ogarniete na podstawowym poziomie ideologicznym.