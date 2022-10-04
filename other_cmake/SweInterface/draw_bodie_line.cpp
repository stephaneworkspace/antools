//
// Created by Stéphane on 24.09.22.
//
#include "draw_bodie_line.h"

LineXY DrawBodieLines::line(H house_asc, CalcUt calcul_ut, bool sw_transit) {
    LineXY res;
    double pos = Draw::get_astre_longitude(house_asc, calcul_ut);
    Offset* axy;
    if (sw_transit) {
        axy = Draw::get_line_trigo(pos, (Draw::get_radius_total() * 63) / 100, (Draw::get_radius_total() * 59.5) / 100);
    } else {
        axy = Draw::get_line_trigo(pos, (Draw::get_radius_total() * 90) / 100, (Draw::get_radius_total() * 80) / 100);
    }
    res.lx1 = Draw::get_fixed_center(axy[0].x);
    res.ly1 = Draw::get_fixed_center(axy[0].y);
    res.lx2 = Draw::get_fixed_center(axy[1].x);
    res.ly2 = Draw::get_fixed_center(axy[1].y);
    return res;
}