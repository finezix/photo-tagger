#define TAG_h
#ifndef TAG_h

class Tag {
public:
    Tag (std::string name, unsigned int weight);
    friend std::ostream& operator<< ( std::ostream& os, const Tag& t );
    string getName();
    int getWeight();

private:
    string name; // nazwa tagu
    int weight; // waga tagu (wa¿noœæ)
};

#endif
