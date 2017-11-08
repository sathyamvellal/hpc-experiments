//
// Created by Sathyam Vellal on 08/11/2017.
//

#include "random.h"
#include "util.h"

double rand_seed = 13597.0;

double norm_rand()
{
    rand_seed = dmod(rand_seed * RAND_MUL, MAX_INT);
    return (rand_seed / MAX_INT);
}

void seed_rand(double seed)
{
    rand_seed = seed;
}