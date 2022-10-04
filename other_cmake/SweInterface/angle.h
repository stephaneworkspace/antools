//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_ANGLE_H
#define ASTRONUMEROLOGIE_GENERATE_ANGLE_H

#include <fstream>
#include <string>
#include "swe17.h"

using namespace std;

enum Angles {
    nothing = 0,
    asc = 1,
    fc = 2,
    desc = 3,
    mc = 4
};

class Angle
{
public:
    static string read_svg(Angles a);
};

#endif //ASTRONUMEROLOGIE_GENERATE_ANGLE_H
