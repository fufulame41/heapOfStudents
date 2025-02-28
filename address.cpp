#include "address.h"
#include <iostream>

Address::Address(){ street(""), city(""), state(""), zip("") 
}

void Address::init(std::string st, std::string c, std::string s, std::string z) {
    street = st;
    city = c;
    state = s;
    zip = z;
}

void Address::printAddress() {
    std::cout << street << "\n" << city << " " << state << ", " << zip << std::endl;
}
