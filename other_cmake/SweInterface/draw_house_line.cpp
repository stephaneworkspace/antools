//
// Created by Stéphane on 24.09.22.
//
#include "draw_house_line.h"

LineXY3 *DrawHouseLines::lines(H *house) {
    const int MAX_HOUSE = 12;
    const double ANGULAR_POINTER = -1;
    const double TRIANGLE_TOP = 79.5;
    const double TRIANGLE_BOTTOM = 76;
    const double LINE_TOP = 80;
    const double LINE_BOTTOM = 76;
    LineXY3* res = new LineXY3[MAX_HOUSE];
    for (int i = 0; i < MAX_HOUSE; ++i) {
        double off_house = 360 - house[0].longitude;
        double pos = Draw::get_fixed_pos(off_house + house[i].longitude);
        Offset* axy_triangle;
        double angular_pointer = ANGULAR_POINTER;
        if (house[i].angle != Angles::asc) {
            Offset* axy_line = Draw::get_line_trigo(pos,
                                                    (Draw::get_radius_total() * LINE_TOP) / 100,
                                                    (Draw::get_radius_total() * LINE_BOTTOM) / 100);
            res[i].lx1 = axy_line[0].x;
            res[i].ly1 = axy_line[0].y;
            res[i].lx2 = axy_line[1].x;
            res[i].ly2 = axy_line[1].y;
            res[i].sw_lxy3 = false;
            res[i].lx3 = 0;
            res[i].ly3 = 0;
        } else {
            axy_triangle = Draw::get_triangle_trigo(pos,
                                                    angular_pointer,
                                                    (Draw::get_radius_total() * TRIANGLE_TOP) / 100,
                                                    (Draw::get_radius_total() * TRIANGLE_BOTTOM) / 100);
            res[i].lx1 = axy_triangle[0].x;
            res[i].ly1 = axy_triangle[0].y;
            res[i].lx2 = axy_triangle[1].x;
            res[i].ly2 = axy_triangle[1].y;
            res[i].sw_lxy3 = true;
            res[i].lx3 = axy_triangle[2].x;
            res[i].ly3 = axy_triangle[2].y;
        }
        res[i].lx1 = Draw::get_fixed_center(res[i].lx1);
        res[i].ly1 = Draw::get_fixed_center(res[i].ly1);
        res[i].lx2 = Draw::get_fixed_center(res[i].lx2);
        res[i].ly2 = Draw::get_fixed_center(res[i].ly2);
        res[i].lx3 = Draw::get_fixed_center(res[i].lx3);
        res[i].ly3 = Draw::get_fixed_center(res[i].ly3);
    }
    return res;
}

LineXY DrawHouseLines::angle_lines(H *house, Angles angle) {
    const double LINE_TOP = 90;
    const double LINE_BOTTOM = 76;
    LineXY res;
    double off_house = 360 - house[0].longitude;
    double pos = 0;
    double line_top = 90;
    switch (angle) {
        case Angles::asc:
            pos = Draw::get_fixed_pos(off_house + house[0].longitude);
            line_top -= 1;
            break;
        case Angles::fc:
            pos = Draw::get_fixed_pos(off_house + house[3].longitude);
            break;
        case Angles::desc:
            pos = Draw::get_fixed_pos(off_house + house[6].longitude);
            line_top -= 2;
            break;
        case Angles::mc:
            pos = Draw::get_fixed_pos(off_house + house[9].longitude);
            break;
        case Angles::nothing:
            break;
    }
    Offset* axy_line = Draw::get_line_trigo(pos,
                                            (Draw::get_radius_total() * line_top) / 100,
                                            (Draw::get_radius_total() * LINE_BOTTOM) / 100);
    res.lx1 = axy_line[0].x;
    res.ly1 = axy_line[0].y;
    res.lx2 = axy_line[1].x;
    res.ly2 = axy_line[1].y;
    res.lx1 = Draw::get_fixed_center(res.lx1);
    res.ly1 = Draw::get_fixed_center(res.ly1);
    res.lx2 = Draw::get_fixed_center(res.lx2);
    res.ly2 = Draw::get_fixed_center(res.ly2);
    return res;
}
