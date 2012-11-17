#ifndef PHOTOLIST_H
#define PHOTOLIST_H

#define MAX_PHOTOS_COUNT 100

#include "photo.h"

#include <string>

/* Holds photo array which is sorted according to result got from
 * calling photo->getWeight(<title of this list>), if result is < 0,
 * the result is used to sort list, else result of calling
 * photo->getTitle() is used as indexer. That way when we need list of pictures
 * taken on a date, we call PhotoList(<date>), and it will be sorted by photo's
 * name, and if we need list sorted by one tag's value, we use
 * constructor PhotoList(<tagTitle>) and it will be sorted by that tag's weight
 * in given pictures.
 */
class PhotoList
{
public:
	PhotoList(const std::string& title);
	
    std::string getTitle(); // returns List's title
    int getSize(); // returns number of held elements
    bool add (Photo* f); // tries to add photo, returns true if succeds
    Photo* get(int index); // returns pointer from list[index], if index >= size, NULL

private:
	std::string listTitle;
    Photo* list [MAX_PHOTOS_COUNT]; // array of held elements
	int size; // count of elements held in array
};

#endif // PHOTOLIST_H