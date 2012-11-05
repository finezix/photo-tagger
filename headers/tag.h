#define TAG_h
#ifndef TAG_h

/* Simple class holding weight of given tag, and that tag's name */
class Tag {
public:
    Tag (std::string name, unsigned int weight);
	Tag(const Tag& other);
	Tag& operator=(const Tag& other);
    friend std::ostream& operator<< ( std::ostream& os, const Tag& t );
	
    std::string getName();
    int getWeight();

private:
    std::string name; // tag's name
    int weight; // tag's weight (importance)
};

#endif
