//
// Created by Stéphane on 25.09.22.
//
#include "draw_house_number.h"

double DrawHouseNumber::number_size() {
    const double HOUSE_SIZE = 20;
    const double HOUSE_RATIO = 8.7;
    return (((HOUSE_SIZE * HOUSE_RATIO) / 100.0) * CHART_SIZE) / 100.0;
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
    Offset trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 77.8) / 100);
    double zs = DrawHouseNumber::number_size();
    res = Draw::get_center_item(zs, trigo);
    return res;
}

