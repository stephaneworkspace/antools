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
    angle angle;
};

class House
{
private:
    string read_svg(int house);
public:
    static H init(int object_id, double longitude, angle angle);
    Image generer(int house, double x, double y, double width, double height);
};

#endif //ASTRONUMEROLOGIE_GENERATE_HOUSE_H
