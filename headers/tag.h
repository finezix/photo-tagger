#ifndef TAG_H
#define TAG_H

#include <ostream>
#include <string>

/* Simple class holding weight of given tag, and that tag's name */
class Tag
{
public:
	Tag();
	Tag(const Tag& other);
    Tag (std::string name, unsigned int weight);
	Tag& operator=(const Tag& other);
    friend std::ostream& operator<< (std::ostream& os, const Tag& t);
	
    std::string getName() const;
    unsigned int getWeight() const;

private:
    std::string name; // tag's name
    unsigned int weight; // tag's weight (importance)
};

#endif // TAG_H