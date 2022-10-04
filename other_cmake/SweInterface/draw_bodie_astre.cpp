//
// Created by Stéphane on 24.09.22.
//
#include "draw_bodie_astre.h"

double DrawBodieAstre::astre_size() {
    const double ASTRE_SIZE = 43;
    const double ASTRE_RATIO = 9;
    return (((ASTRE_SIZE * ASTRE_RATIO) / 100.0) * CHART_SIZE) / 100.0;
}

Offset DrawBodieAstre::bodie_astre(H house_asc, CalcUt calcul_ut, bool sw_transit) {
    Offset res;
    double pos;
    pos = Draw::get_astre_longitude(house_asc, calcul_ut);
    Offset offset_trigo;
    if (sw_transit) {
        offset_trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 55) / 100);
    } else {
        offset_trigo = Draw::get_pos_trigo(pos, (Draw::get_radius_total() * 95) / 100);
    }
    double as = astre_size();
    res = Draw::get_center_item(as, offset_trigo);
    return res;
}