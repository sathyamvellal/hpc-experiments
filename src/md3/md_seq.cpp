//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>
#include <cmath>

#include "3d.h"
#include "util.h"
#include "random3.h"
#include <ctime>

#include "md3/md.h"

void Simulation::init() {
    atoms = system.atoms;

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
                        atoms[num_atoms].r[k] = c[k] + gap[k] * orig_atom[j][k];
                    }
                    ++num_atoms;
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
            atoms[n].v[k] = vMag * e[k];
            vSum[k] += atoms[n].v[k];
        }
    }

    for (int k = X; k < NDIM; ++k) {
        vSum[k] /= num_atoms;
    }
    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            atoms[n].v[k] -= vSum[k];
        }
    }
}

void Simulation::compute_accel()
{
    const double rrCut = RCUT * RCUT;
    double rr, dr[NDIM];

    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            atoms[n].a[k] = 0.0;
        }
    }
    system.pot_energy = 0.0;

    for (int i = 0; i < num_atoms - 1; ++i) {
        for (int j = i+1; j < num_atoms; ++j) {
            rr = 0.0;
            for (int k = X; k < NDIM; ++k) {
                dr[k] = atoms[i].r[k] - atoms[j].r[k];
                dr[k] += - signr(region_half[k], dr[k] - region_half[k]) - signr(region_half[k], dr[k] + region_half[k]);
                rr += dr[k] * dr[k];
            }

            if (rr < rrCut) {
                const double ri2 = 1.0 / rr;
                const double ri6 = ri2 * ri2 * ri2;
                const double r1 = sqrt(rr);
                const double fcVal = 48.0 * ri2 * ri6 * (ri6 - 0.5) + (Duc / r1);

                for (int k = X; k < NDIM; ++k) {
                    const double f = fcVal * dr[k];
                    atoms[i].a[k] += f;
                    atoms[j].a[k] -= f;
                }

                system.pot_energy += 4.0 * ri6 * (ri6 - 1.0) - Uc - (Duc * (r1 - RCUT));
            }
        }
    }
}

void Simulation::apply_boundary_condition()
{
    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            atoms[n].r[k] += - signr(region_half[k], atoms[n].r[k]) - signr(region_half[k], atoms[n].r[k] - region[k]);
        }
    }
}

void Simulation::half_kick()
{
    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            atoms[n].v[k] += halfdelta_t * atoms[n].a[k];
        }
    }
}

void Simulation::single_step()
{
    half_kick();
    for (int n = 0; n < num_atoms; ++n) {
        for (int k = X; k < NDIM; ++k) {
            atoms[n].r[k] += delta_t * atoms[n].v[k];
        }
    }
    apply_boundary_condition();
    compute_accel();
    half_kick();
}

void Simulation::run()
{
    double cpu1 = ((double) clock()) / CLOCKS_PER_SEC;
    for (int step = 1; step <= num_steps; ++step) {
        single_step();
    }
    double cpu2 = ((double) clock()) / CLOCKS_PER_SEC;

    exec_time = cpu2 - cpu1;
}