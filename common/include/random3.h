//
// Created by Sathyam Vellal on 08/11/2017.
//

#ifndef HPC_EXPERIMENTS_RAND_H
#define HPC_EXPERIMENTS_RAND_H

// Lehmer random number generator

extern double rand_seed;

const double MAX_INT = 2147483647.0;
const double RAND_MUL = 16807.0;

double norm_rand();
void norm_rand3(double *vec);
void seed_rand(double seed);

#endif //HPC_EXPERIMENTS_RAND_H
