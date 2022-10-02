//
// Created by Stéphane on 25.09.22.
//
#include "draw_house_angle.h"

double DrawHouseAngle::angle_size() {
    const double ANGLE_SIZE = 63;
    const double ANGLE_RATIO = 10;
    return (((ANGLE_SIZE * ANGLE_RATIO) / 100.0) * CHART_SIZE) / 100.0;
}

Offset DrawHouseAngle::angle(H* house, enum angle angle) {
    Offset res;
    double as = DrawHouseAngle::angle_size();
    double pos = Draw::get_angle_longitude(house, angle);
    Offset trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 95) / 100);
    res = Draw::get_center_item(as, trigo);
    res.y = Draw::get_fixed_y(res.y);
    if (angle == angle::mc) {
        res.y = CHART_SIZE;
    }
    return res;
}