//
// Created by Sathyam Vellal on 25/10/2017.
//

#include <iostream>

#include "md/md.h"
#include "util.h"

int main(int argc, char **argv) {
    Simulation simulation;

    simulation.init();

    std::cout << simulation.system.atoms[0].r[X] << std::endl;

    return 0;
}
