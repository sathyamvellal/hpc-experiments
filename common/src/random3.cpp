//
// Created by Sathyam Vellal on 08/11/2017.
//

#include <cmath>

#include "random3.h"
#include "util.h"

#include "3d.h"

double rand_seed = 13597.0;

double norm_rand()
{
    rand_seed = dmod(rand_seed * RAND_MUL, MAX_INT);
    return (rand_seed / MAX_INT);
}

void norm_rand3(double *vec)
{
    double x, y, s = 2.0;
    while (s > 1.0) {
        x = 2.0 * norm_rand() - 1.0;
        y = 2.0 * norm_rand() - 1.0;
        s = (x * x) + (y * y);
    }
    vec[Z] = 1.0 - 2.0 * s;
    s = 2.0 * sqrt(1.0 - s);
    vec[X] = s * x;
    vec[Y] = s * y;
}

void seed_rand(double seed)
{
    rand_seed = seed;
}