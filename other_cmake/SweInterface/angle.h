//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_ANGLE_H
#define ASTRONUMEROLOGIE_GENERATE_ANGLE_H

#include <fstream>
#include <string>
#include "swe17.h"
#include "simple_svg_1.0.0.hpp"

using namespace std;

enum angle {
    nothing = 0,
    asc = 1,
    fc = 2,
    desc = 3,
    mc = 4
};

class Angle
{
private:
    string read_svg(angle a);
public:
    Image generer(angle angle, double x, double y, double width, double height);
};

#endif //ASTRONUMEROLOGIE_GENERATE_ANGLE_H
