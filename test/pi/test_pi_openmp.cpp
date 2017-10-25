//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>
#include <iomanip>
#include "omp.h"

#include "pi/pi.h"

int main(int argc, char **argv) {
    double PI = pi();

    std::cout << "PI: " << std::setprecision(15) << PI << std::endl;

    return 0;
}