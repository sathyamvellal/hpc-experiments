//
// Created by Sathyam Vellal on 25/10/2017.
//

#ifndef HPC_EXPERIMENTS_MD_H
#define HPC_EXPERIMENTS_MD_H

#include "3d.h"
#include "constants.h"

const int NMAX = 100000;

class Atom {
public:
    double r[NDIM];
    double v[NDIM];
    double a[NDIM];
};

class System {
public:
    Atom atoms[NMAX];
    double kin_energy;
    double pot_energy;
    double tot_energy;
    double temp;
};

class Simulation {
public:
    System system;
    int init_ucell[NDIM];
    int num_atoms;
    double density;
    double init_temp;
    double delta_t;
    double num_steps;
    double step_avg;
    double region[NDIM];
    double region_half[NDIM];
    double halfdelta_t;
    double Uc, Duc;
    double step;

    void init();
private:
    void init_region();
    void init_UcDuc();
    void init_fcc();
    void init_velocities();
};

#endif //HPC_EXPERIMENTS_MD_H
