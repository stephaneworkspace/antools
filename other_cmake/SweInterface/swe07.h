//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE07_H
#define ASTRONUMEROLOGIE_GENERATE_SWE07_H

#include <iostream>
#include <fstream>
#include "../Swe/Swe.h"
#include "swe17.h"
#include "astre.h"
#include "option_flag.h"
#include <string>

using namespace std;

struct PhenoUt {
    double phase_angle;
    double phase_illuminated;
    double elongation_of_planet;
    double apparent_diameter_of_disc;
    double apparent_magnitude;
    int status;
    string serr;
};

class Swe07
{
public:
    PhenoUt calc_ut(double tjd_ut, Astres ipl, OptionFlag iflag);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE07_H
