//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>
#include <cmath>

#include "3d.h"
#include "util.h"
#include "random3.h"

#include "md3/md.h"

void Simulation::init() {
    init_region();
    init_UcDuc();
    init_fcc();
    init_velocities();
}

void Simulation::init_region()
{
    halfdelta_t = 0.5 * delta_t;
    for (int k = X; k < NDIM; ++k) {
        region[k] = init_ucell[k] / pow(density / 4.0, 1.0 / 3.0);
        region_half[k] = 0.5 * region[k];
    }
}

void Simulation::init_UcDuc()
{
    const double rr = RCUT * RCUT;
    const double ri2 = 1.0 / rr;
    const double ri6 = ri2 * ri2 * ri2;
    const double r1 = sqrt(rr);
    Uc = 4.0 * ri6 * (ri6 - 1.0);
    Duc = -48.0 * ri6 * (ri6 - 0.5) / r1;
}

void Simulation::init_fcc()
{
    double gap[NDIM], c[NDIM];

    const double orig_atom[4][NDIM] = {
            { .0, .0, .0 },
            { .0, .5, .5 },
            { .5, .0, .5 },
            { .5, .5, .0 }
    };

    for (int k = X; k < NDIM; ++k) {
        gap[k] = region[k] / init_ucell[k];
    }

    num_atoms = 0;

    for (int z = 0; z < init_ucell[Z]; ++z) {
        c[Z] = z * gap[Z];
        for (int y = 0; y < init_ucell[Y]; ++y) {
            c[Y] = y * gap[Y];
            for (int x = 0; x < init_ucell[X]; ++x) {
                c[X] = x * gap[X];
                for (int j = 0; j < 4; ++j) {
                    for (int k = X; k < NDIM; ++k) {
                        system.atoms[num_atoms].r[k] = c[k] + gap[k] * orig_atom[j][k];
                    }
                }
            }
        }
    }
}

void Simulation::init_velocities()
{
    double vMag = sqrt(3 * init_temp);
    double vSum[NDIM] = {0.0};
    double e[NDIM];

    for (int n = 0; n < num_atoms; ++n) {
        norm_rand3(e);
        for (int k = X; k < NDIM; ++k) {
            system.atoms[n].v[k] = vMag * e[k];
            vSum[k] += system.atoms[n].v[k];
        }
    }

    for (int k = X; k < NDIM; ++k) {
        vSum[k] /= num_atoms;
    }
    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            system.atoms[n].v[k] -= vSum[k];
        }
    }
}