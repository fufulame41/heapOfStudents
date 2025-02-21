#include "student.h"
#include "address.h"
#include "date.h"
#include <iostream>
#include <sstream>

Student::student(){
    studentString = "";
    firstName = "";
    lastName = "";
    dob = new Date();
    gradDate = new Date();
    address = new Adress();
    creditHours = 0;
}

Student::Student(std::string studentString){
   Student::init(studentString);
}

Student::~Student(){
    delete dob;
    delete gradDate;
    delete address;
}

void Student::init(std::string studentString){
    std::stringstream ss(studentString);
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string tDob;
    std::string tGradDate;
    std::string tCreditHours;

    getline(ss, firstname, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, tDob, ',');
    getline(ss, tGradDate, ',');
    getline(ss, tCreditHours, ',');

    address->init(street, city, state, zip);
    dob->init(tDob);
    gradDate->init(tGradDate);

    ss.clear();
    ss.str(tCreditHours);
    ss >> creditHours;
}

void Student::printStudent(){
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();

    std::cout << "DOB: ";
    dob->printDate();
    std::cout << "Grad: ";
    GradDate->printDate();

    std::cout << "Credits: " << creditHours << std::endl;
    std::cout << "____________________________________";
    std::cout << std::endl;
}

std::string student::getLastFirst(){
    std::stringstream ss;
    ss.clear();
    ss << lastName << ", " << firstName;
    return ss.str();
}

std::string Student::getLastName(){
  return lastName;
}

std::string Student::getFirstName() const {
    return firstName;
}

int Student::getCreditHours() const {
    return creditHours;
}
