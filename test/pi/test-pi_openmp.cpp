//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include "omp.h"

#include "pi/pi.h"

int main(int argc, char **argv) {
    double PI;

    clock_t time_begin = clock();
    PI = pi();
    clock_t time_end = clock();

    std::cout << "PI: " << std::setprecision(15) << PI << std::endl;
    std::cout << "CPU: " << std::setprecision(10) << (double)(time_end - time_begin)/(CLOCKS_PER_SEC) << std::endl;

    return 0;
}