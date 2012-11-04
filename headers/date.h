#define DATE_h
#ifndef DATE_h

class Date {
public:
    Date (unsigned int dd, unsigned int mm, unsigned int yyyy);
    friend std::ostream& operator<< ( std::ostream& os, const Date& d );
    int compareTo(Date d); //int
    string toString(); // string

private:
    int dd;
    int mm;
    int yyyy;
};

#endif
