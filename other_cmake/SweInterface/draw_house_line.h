//
// Created by Stéphane on 24.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_LINE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_LINE_H

#include "draw.h"

class DrawHouseLines
{
public:
    LineXY3* lines(H* house);
    LineXY angle_lines(H* house, angle angle);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_LINE_H
