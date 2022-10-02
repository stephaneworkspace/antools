//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE03_H
#define ASTRONUMEROLOGIE_GENERATE_SWE03_H

#include <iostream>
#include <fstream>
#include "../Swe/Swe.h"
#include "calcul_ut.h"
#include "swe17.h"
#include "astre.h"
#include "option_flag.h"
#include <string>

using namespace std;

class Swe03
{
public:
    static CalcUt calc_ut(double tjd_ut, Astres ipl, OptionFlag iflag);
    static void display(CalcUt calcul_ut);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE03_H
