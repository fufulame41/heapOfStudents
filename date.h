
#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
    protected:
    std::string dateString;
    int day;
    int month;
    int year;

    public:
    Date();
    void init(const std::string& dateString);
    void printDate();
};

#endif
