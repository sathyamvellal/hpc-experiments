//
// Created by Sathyam Vellal on 08/11/2017.
//

#include "random.h"
#include "util.h"

double rand_seed = 13597.0;

double norm_rand()
{
    random_seed = dmod(random_seed * RAND_MUL, MAX_INT);
    return (random_seed / MAX_INT);
}

void seed_rand(double seed)
{
    random_seed = seed;
}