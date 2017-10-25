//
// Created by Sathyam Vellal on 24/10/2017.
//

#include <iostream>
#include <iomanip>

#include "hello.h"
#include "pi/pi.h"

int main(int argc, char **argv) {
    hello();

    double PI;
    PI = pi();
    std::cout << "PI: " << std::setprecision(20) << PI << std::endl;

    return 0;
}