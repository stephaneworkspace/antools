//
// Created by Stéphane on 25.09.22.
//
#include "draw_house_number.h"

Size DrawHouseNumber::number_size(int house_number) {
    Size size;
    const double HOUSE_SIZE = 20;
    const double HOUSE_RATIO = 8.7;
    const double ANTONIO_RATIO = 3;
    double width = 0;
    double height = 0;
    switch (house_number) {
        case 1:
            width = 12 * ANTONIO_RATIO;
            height = 43 * ANTONIO_RATIO;
            break;
        case 2:
            width = 18 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 3:
            width = 19 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 4:
            width = 20 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 5:
            width = 18 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 6:
            width = 20 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 7:
            width = 19 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 8:
            width = 19 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 9:
            width = 19 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 10:
            width = 38 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 11:
            width = 29 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        case 12:
            width = 37 * ANTONIO_RATIO;
            height = 44 * ANTONIO_RATIO;
            break;
        default:
            width = HOUSE_SIZE * HOUSE_RATIO;
            height = HOUSE_SIZE * HOUSE_RATIO;
            break;
    }
    size.width = ((width / 100.0) * CHART_SIZE) / 100.0;
    size.height = ((height / 100.0) * CHART_SIZE) / 100.0;
    return size;
}

Offset DrawHouseNumber::number(int house_number, H* house) {
    Offset res;
    double off_pos_asc = 360 - house[0].longitude;
    double pos_next;
    if (house_number > 11) {
        pos_next = house[0].longitude + off_pos_asc;
    } else {
        pos_next = house[house_number].longitude + off_pos_asc;
    }
    double pos_now = house[house_number - 1].longitude + off_pos_asc;
    double pos;
    if (pos_now > pos_next) {
        pos = pos_now + ((pos_next - pos_now - 360) / 2);
    } else {
        pos = pos_now + ((pos_next - pos_now) / 2);
    }
    pos = Draw::get_fixed_pos(pos);
    Offset trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 78) / 100);
    Size zs = DrawHouseNumber::number_size(house_number);
    res = Draw::get_center_item(zs.width, zs.height, trigo);
    return res;
}

