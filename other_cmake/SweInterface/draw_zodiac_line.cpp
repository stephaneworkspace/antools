//
// Created by Stéphane on 22.09.22.
//
#include "draw_zodiac_line.h"

double DrawZodiacLines::get_radius_rules_inside_circle(larger_draw_line ldl) {
    double size;
    switch (ldl) {
        case larger_draw_line::small:
            size = 74.5;
            break;
        case larger_draw_line::large:
            size = 73;
            break;
    }
    return (Draw::get_radius_total() * (size)) / 100;
}

LineXY* DrawZodiacLines::line(H house_asc) {
    LineXY* res = new LineXY[12 * 16];
    int j = 0;
    for (int i = 0; i < 12; ++i) {
        // 0°
        double off_pos_asc = 360 - house_asc.longitude;
        double pos = i * 30 + off_pos_asc;
        pos = Draw::get_fixed_pos(pos);
        Offset* axy = Draw::get_line_trigo(pos,
                                           (Draw::get_radius_total() * 76) / 100,
                                           (Draw::get_radius_total() * 63) / 100);
        res[j].lx1 = Draw::get_fixed_center(axy[0].x);
        res[j].ly1 = Draw::get_fixed_center(axy[0].y);
        res[j].lx2 = Draw::get_fixed_center(axy[1].x);
        res[j].ly2 = Draw::get_fixed_center(axy[1].y);
        j++;
        // 1° to 29°
        larger_draw_line ldl;
        for (int k = 0; k < 15; ++k) {
            if (k == 5 || k == 10 || k == 15) {
                ldl = larger_draw_line::large;
            } else {
                ldl = larger_draw_line::small;
            }
            pos = (i * 30) + (k * 2) + off_pos_asc;
            pos = Draw::get_fixed_pos(pos);
            axy = Draw::get_line_trigo(pos,
                                       Draw::get_radius_total() * 76 / 100,
                                       DrawZodiacLines::get_radius_rules_inside_circle(ldl));
            res[j].lx1 = Draw::get_fixed_center(axy[0].x);
            res[j].ly1 = Draw::get_fixed_center(axy[0].y);
            res[j].lx2 = Draw::get_fixed_center(axy[1].x);
            res[j].ly2 = Draw::get_fixed_center(axy[1].y);
            j++;
        }
    }
    return res;
}

