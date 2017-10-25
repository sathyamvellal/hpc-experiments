//
// Created by Sathyam Vellal on 24/10/2017.
//

#include "mpi.h"

#include "pi/pi.h"


double pi() {
    const double step = 1.0 / N;

    double x;
    double sum = 0.0, partial_sum = 0.0;

    int id, np;

    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    for (long int i = id; i < N; i += np) {
        x = (i + 0.5) * step;
        partial_sum += 4.0 / (1.0 + x * x);
    }

    MPI_Allreduce(&partial_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return sum / N;
}