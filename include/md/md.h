//
// Created by Sathyam Vellal on 25/10/2017.
//

#ifndef HPC_EXPERIMENTS_MD_H
#define HPC_EXPERIMENTS_MD_H

#include "md/md_constants.h"
#include "3d_constants.h"

const int NMAX = 100000;

struct Atom {
    double r[NUM_DIMENS];
    double v[NUM_DIMENS];
    double a[NUM_DIMENS];
};

struct System {
    Atom atoms[NMAX];
};

struct Simulation {
    System system;

    void init();
};

#endif //HPC_EXPERIMENTS_MD_H
