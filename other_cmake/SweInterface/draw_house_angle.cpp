//
// Created by Stéphane on 25.09.22.
//
#include "draw_house_angle.h"

Size DrawHouseAngle::angle_size(Angles angle) {
    Size size;
    const double ANGLE_SIZE = 63;
    const double ANGLE_RATIO = 10;
    double width = 0;
    double height = 0;
    switch (angle) {
        case Angles::asc:
            width = 44 * 5.5;
            height = 44 * 5.5;
            //width = 65 * 5.5;
            //height = 44 * 5.5;
            break;
        case Angles::fc:
            width = 37 * 5.5;
            height = 44 * 5.5;
            break;
        case Angles::desc:
            width = 44 * 5.5;
            height = 44 * 5.5;
            //width = 87 * 5.5;
            //height = 44 * 5.5;
            break;
        case Angles::mc:
            width = 53 * 5.5;
            height = 44 * 5.5;
            break;
        default:
            width = ANGLE_SIZE * ANGLE_RATIO;
            height = ANGLE_SIZE * ANGLE_RATIO;
            break;
    }
    size.width = ((width / 100) * CHART_SIZE) / 100;
    size.height = ((height / 100) * CHART_SIZE) / 100;
    return size;
}

Offset DrawHouseAngle::angle(H* house, Angles angle) {
    double pos = Draw::get_angle_longitude(house, angle);
    Offset trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 95) / 100);

    Offset res;
    Size as = DrawHouseAngle::angle_size(angle);
    res = Draw::get_center_item(as.width, as.height, trigo);
    return res;
}