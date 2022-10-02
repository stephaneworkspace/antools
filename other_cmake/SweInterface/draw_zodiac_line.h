//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_LINE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_LINE_H

#include "draw.h"
#include "draw_zodiac_circle.h"
#include "sign.h"
#include "swe02.h"
#include "swe08.h"
#include "house.h"
#include "timezone.h"

enum larger_draw_line {
    small,
    large
};

class DrawZodiacLines
{
private:
    double get_radius_rules_inside_circle(larger_draw_line ldl);
public:
    LineXY* line(H house_asc);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_LINE_H
