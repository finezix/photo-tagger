#ifndef DATE_h
#define DATE_h

#include <string>
#include <ostream>

/* Unmodifiable class holding simple ints, capable of writing itself to out stream,
 * comparing itself to other dates, and returning string containing it */
class Date
{
public:
    Date (unsigned int dd, unsigned int mm, unsigned int yyyy);
	Date (const Date& other);
	Date& operator= (const Date& other);
    friend std::ostream& operator<< (std::ostream& os, const Date& d );
	
    int compareTo(const Date& d); //int
    std::string toString(); // string

private:
    unsigned int dd;
    unsigned int mm;
    unsigned int yyyy;
};

#endif
