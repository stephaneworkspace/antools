//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE17_H
#define ASTRONUMEROLOGIE_GENERATE_SWE17_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "../Swe/Swe.h"
#include "sign.h"
#include <string>

using namespace std;

struct SplitDeg {
    string print;
    int deg;
    int min;
    int sec;
    double cdegfr;
    Signs sign;
    double result;
};

class Swe17
{
public:
    static SplitDeg split_deg(double ddeg, int roundflag);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE17_H
