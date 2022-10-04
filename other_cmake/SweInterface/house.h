//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_HOUSE_H
#define ASTRONUMEROLOGIE_GENERATE_HOUSE_H

#include <iostream>
#include <fstream>
#include "angle.h"
#include "swe17.h"

using namespace std;

struct H {
    int object_id;
    double longitude;
    SplitDeg split;
    Angles angle;
};

class House
{
public:
    static string read_svg(int house);
    static H init(int object_id, double longitude, Angles angle);
};

#endif //ASTRONUMEROLOGIE_GENERATE_HOUSE_H
