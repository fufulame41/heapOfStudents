#include "data.h"
#include "address.h"

#include<iostream>
#include<sstream>

Student::student(){
    studentString = "";
    firstName = "";
    lastName = "";
    dob = new Date();
    gradDate = new Date();
    address = new Adress();
    creditHours = 0;
}


