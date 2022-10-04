//
// Created by Stéphane on 23.09.22.
//
#include "draw_zodiac_sign.h"

double DrawZodiacSign::zodiac_size() {
    const double ZODIAC_SIZE = 43;
    const double ZODIAC_RATIO = 9;
    return (((ZODIAC_SIZE * ZODIAC_RATIO) / 100.0) * CHART_SIZE) / 100.0;
}

Offset DrawZodiacSign::zodiac_sign(Signs sign, H house_asc) {
    Offset res;
    double off_pos_asc = 360 - house_asc.longitude;
    int s = int(sign - 1);
    double pos = (s * 30) + 15 + off_pos_asc;
    Offset trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 69) / 100);
    double zs = DrawZodiacSign::zodiac_size();
    res = Draw::get_center_item(zs, trigo);
    return res;
}

