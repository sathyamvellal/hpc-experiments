//
// Created by Sathyam Vellal on 27/10/2017.
//

#include "util.h"

double dmod(double num, double mod) {
    int a;
    a = (int) (num/mod);
    return (num - mod * a);
}

