//
// Created by Stéphane on 27.09.22.
//
#include "draw_aspect_line.h"

LineXYAspect DrawAspectLines::line(H house_asc, double* item_longitude) {
    const double CIRCLE_CENTER_POS = 360 * 40 / 100;
    LineXYAspect res;
    res.sw = false;
    double* longitude = new double[2];
    for (int i = 0; i < 2; ++i) {
        longitude[i] = Draw::get_item_longitude(house_asc, item_longitude[i]);
    }
    double separation = Draw::get_closest_distance(longitude);
    double abs_separation = abs(separation);
    for (int i = 0; i < int(Aspects::semisextile); ++i) {
        Aspects a = static_cast<Aspects>(i);
        int* angle = Aspect::angle(a);
        int asp = angle[0];
        int orb = angle[1];
        int abs_calc = abs(abs_separation - asp) ;
        if (abs_calc <= orb) {
            Offset* pos = new Offset[2];
            for (int j = 0; j < 2; ++j) {
                pos[j] = Draw::get_pos_trigo(longitude[j], CIRCLE_CENTER_POS);
            }
            res.aspect = a;
            res.sw = true;
            res.lx1 = pos[0].x;
            res.ly1 = pos[0].y;
            res.lx2 = pos[1].x;
            res.ly2 = pos[1].y;
            /*res.lx1 = Draw::get_fixed_center(res.lx1);
            res.ly1 = Draw::get_fixed_center(res.ly1);
            res.lx2 = Draw::get_fixed_center(res.lx2);
            res.ly2 = Draw::get_fixed_center(res.ly2);
            */
            return res;
        }
    }
    return res;
}

