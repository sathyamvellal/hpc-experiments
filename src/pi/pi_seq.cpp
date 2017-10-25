//
// Created by Sathyam Vellal on 24/10/2017.
//

#include "pi/pi.h"


double pi() {
    const double step = 1.0 / N;

    double x;
    double sum = 0.0;

    for (long int i = 0; i < N; ++i) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    return sum / N;
}