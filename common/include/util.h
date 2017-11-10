//
// Created by Sathyam Vellal on 27/10/2017.
//

#ifndef HPC_EXPERIMENTS_UTIL_H
#define HPC_EXPERIMENTS_UTIL_H

double dmod(double num, double mod);
inline double signr(double val, double x)
{
    return (x > 0.0) ? val : -val;
}

#endif //HPC_EXPERIMENTS_UTIL_H
