//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_CIRCLE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_CIRCLE_H

#include "draw.h"

enum circle_position {
    zero = 0,
    un = 1,
    deux = 2,
    trois = 3,
    quatre = 4,
    cinq = 5,
    six = 6,
    sept = 7,
    huit = 8,
};

struct CirclePosition {
    double pcent;
    double pcent_divider;
    bool sw;
};

const CirclePosition CIRCLE_SIZE_0 = CirclePosition {60, 42 * CHART_SIZE_DIVID, true};
const CirclePosition CIRCLE_SIZE_1 = CirclePosition {79, 59 * CHART_SIZE_DIVID, true};
const CirclePosition CIRCLE_SIZE_2 = CirclePosition {95, 75 * CHART_SIZE_DIVID, true};
const CirclePosition CIRCLE_SIZE_3 = CirclePosition {100, 80 * CHART_SIZE_DIVID, true};
const CirclePosition CIRCLE_SIZE_4 = CirclePosition {112, 92 * CHART_SIZE_DIVID, false};
const CirclePosition CIRCLE_SIZE_5 = CirclePosition {112, 92 * CHART_SIZE_DIVID, false};
const CirclePosition CIRCLE_SIZE_6 = CirclePosition { 0,  0 * CHART_SIZE_DIVID, false};
const CirclePosition CIRCLE_SIZE_7 = CirclePosition {82, 82 * CHART_SIZE_DIVID, false};
const CirclePosition CIRCLE_SIZE_8 = CirclePosition {85, 85 * CHART_SIZE_DIVID, false};

struct CircleZod {
    double center;
    double radius;
    double radius_multiplier;
    double radius_divider;
    bool sw;
};

class DrawCircle
{
private:
    CirclePosition get_radius_circle(circle_position circlePosition);
public:
    CircleZod circle(circle_position circle_position);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_CIRCLE_H
