//
// Created by Sathyam Vellal on 24/10/2017.
//

#include <iostream>
#include "omp.h"

#include "pi/pi.h"


double pi() {
    const long int N = 1000l * 1000l * 1000l * 10l;
    const double step = 1.0 / N;

    double x;
    double sum = 0.0;

    omp_set_num_threads(8);

    #pragma omp parallel private(x) reduction(+:sum)
    {
        std::cout << "Boo" << std::endl;
        #pragma omp for
        for (long int i = 0; i < N; ++i) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
    }

    return sum / N;
}