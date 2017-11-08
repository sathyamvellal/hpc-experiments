//
// Created by Sathyam Vellal on 25/10/2017.
//

#ifndef HPC_EXPERIMENTS_MD_H
#define HPC_EXPERIMENTS_MD_H

#include "3d.h"
#include "constants.h"

const int NMAX = 100000;

struct Atom {
    double r[NDIM];
    double v[NDIM];
    double a[NDIM];
};

struct System {
    Atom atoms[NMAX];
};

struct Simulation {
    System system;

    void init();
};

#endif //HPC_EXPERIMENTS_MD_H
