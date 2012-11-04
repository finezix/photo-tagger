#define DATE_h
#ifndef DATE_h

class Date {
public:
    int compareTo(Date d); //int
    string toString(); // string

private:
    int dd;
    int mm;
    int yyyy;
};

#endif
