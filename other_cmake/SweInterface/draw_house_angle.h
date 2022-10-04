//
// Created by Stéphane on 25.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_ANGLE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_ANGLE_H

#include "draw.h"
#include "sign.h"
#include "house.h"

class DrawHouseAngle
{
public:
    static Size angle_size(Angles angle);
    static Offset angle(H* house, Angles angle);
};
#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_ANGLE_H
