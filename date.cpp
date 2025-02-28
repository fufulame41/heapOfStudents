#include "date.h"
#include <iostream>
#include <sstream>

Date::Date(){
    day = 0;
    month = 0;
    year = 0;
}

void Date::init(const std::string& dateString) {
    std::stringstream ss(dateString);
    char delimiter;
    ss >> month >> delimiter >> day >> delimiter >> year;
}

void Date::printDate() const {
    std::string months[] = {"Null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << months[month] << " " << day << ", " << year << std::endl;
}
