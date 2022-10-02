//
// Created by Stéphane on 27.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_ASPECT_LINE_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_ASPECT_LINE_H

#include "draw.h"
#include "aspect.h"
#include "astre.h"
#include "house.h"
#include "swe03.h"

class DrawAspectLines
{
public:
    static LineXYAspect line(H house_asc, double* item_longitude);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_ASPECT_LINE_H
