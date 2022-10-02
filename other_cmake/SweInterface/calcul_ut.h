//
// Created by Stéphane on 29.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_CALCUL_UT_H
#define ASTRONUMEROLOGIE_GENERATE_CALCUL_UT_H

#include "swe17.h"

struct CalcUt {
    double longitude;
    double latitude;
    double distance_au;
    double speed_longitude;
    double speed_latitude;
    double speed_distance_au;
    int status;
    string serr;
    SplitDeg split;
};


#endif //ASTRONUMEROLOGIE_GENERATE_CALCUL_UT_H
