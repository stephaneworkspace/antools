//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_DRAW_H
#define ASTRONUMEROLOGIE_GENERATE_DRAW_H

#include <cmath>
#include "aspect.h"
#include "house.h"
#include "swe03.h"

const int CHART_SIZE = 600;
const double CHART_SIZE_MULTI = 1.6;
const double CHART_SIZE_DIVID = 0.6;
double const STROKE_FINE = 0.5;
double const STROKE_BOLD = 2;

struct Size {
    double width;
    double height;
};

struct Offset {
    double x;
    double y;
};

struct LineXY {
    double lx1;
    double ly1;
    double lx2;
    double ly2;
};

struct LineXY3 {
    double lx1;
    double ly1;
    double lx2;
    double ly2;
    double sw_lxy3;
    double lx3;
    double ly3;
};

struct LineXYAspect {
    double lx1;
    double ly1;
    double lx2;
    double ly2;
    bool sw;
    Aspects aspect;
};

struct PairAspect {
    int i;
    int j;
};

class Draw
{
public:
    static double get_fixed_center(double pos_value);
    static double get_fixed_pos(double pos_value);
    static Offset get_center_item(double size, Offset offset);
    static Offset get_center_item(double width, double height, Offset offset);
    static Offset get_pos_trigo(double angular, double radius_circle);
    static double get_radius_total();
    static Offset* get_line_trigo(double angular, double radius_circle_begin, double radius_circle_end);
    static double get_astre_longitude(H house, CalcUt calcul_ut);
    static double get_item_longitude(H house, double longitude);
    static Offset* get_triangle_trigo(double angular,
                                      double angular_pointer,
                                      double radius_circle_begin,
                                      double radius_circle_end);
    static double get_sign_longitude(H house_asc, CalcUt calcul_ut);
    static double get_angle_longitude(H* house, Angles angle);
    static double get_z_norm(double angle);
    static double get_closest_distance(double* angle);
};

#endif //ASTRONUMEROLOGIE_GENERATE_DRAW_H