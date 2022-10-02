//
// Created by Stéphane on 25.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_NUMBER_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_NUMBER_H

#include "draw.h"
#include "house.h"

class DrawHouseNumber
{
public:
    static double number_size();
    static Offset number(int house_number, H* house);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_HOUSE_NUMBER_H
