//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_SWE14_H
#define ASTRONUMEROLOGIE_GENERATE_SWE14_H

#include <iostream>
#include <fstream>
#include <string>
#include "angle.h"
#include "house.h"
#include "../Swe/Swe.h"

using namespace std;

class Swe14
{
public:
    static H house(double tjd_ut, double geo_lat, double geo_lng, char hsys, int house);
};

#endif //ASTRONUMEROLOGIE_GENERATE_SWE14_H
