//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include "mpi.h"

#include "pi/pi.h"

int main(int argc, char **argv) {
    double PI;
    int id, np;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    clock_t time_begin = clock();
    PI = pi();
    clock_t time_end = clock();

    if (id == 0) {
        std::cout << "PI: " << std::setprecision(15) << PI << std::endl;
        std::cout << "CPU: " << std::setprecision(10) << (double) (time_end - time_begin) / (CLOCKS_PER_SEC)
                  << std::endl;
    }

    MPI_Finalize();

    return 0;
}