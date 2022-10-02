//
// Created by Stéphane on 23.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_SIGN_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_SIGN_H

#include "draw.h"
#include "sign.h"
#include "house.h"

class DrawZodiacSign
{
public:
    static double zodiac_size();
    static Offset zodiac_sign(Signs sign, H house_asc);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_ZODIAC_SIGN_H
