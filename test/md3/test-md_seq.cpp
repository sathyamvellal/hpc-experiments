//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>

#include "util.h"
#include "3d.h"
#include "md3/md.h"
#include <ctime>

int main(int argc, char **argv) {
    Simulation simulation;

    simulation.init_ucell[X] = simulation.init_ucell[Y] = simulation.init_ucell[Z] = 4;
    simulation.density = 0.8;
    simulation.init_temp = 1.0;
    simulation.delta_t = 0.005;
    simulation.num_steps = 10;
    simulation.step_avg = 11;

    simulation.init();
    simulation.compute_accel();

    simulation.run();

    std::cout << "Execution time (s) = " << simulation.exec_time << std::endl;

    return 0;
}
