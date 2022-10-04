//
// Created by Stéphane on 24.09.22.
//
#include "draw.h"

double Draw::get_fixed_center(double pos_value) {
    return pos_value + CHART_SIZE / 2;
}

double Draw::get_fixed_y(double y) {
    if (y < 0) {
        y += CHART_SIZE;
    } else {
        if ((y > CHART_SIZE / 2) || (y < CHART_SIZE / 2)) {
            y = CHART_SIZE - y;
        }
        if (y > CHART_SIZE) {
            y -= CHART_SIZE;
        } else if (y < 0) {
            y += CHART_SIZE;
        }
    }
    return y;
}

double Draw::get_fixed_pos(double pos_value) {
    double pos = pos_value;
    bool sw_done = false;
    while (!sw_done) {
        if (pos >= 360) {
            pos = pos - 360;
        }
        if (pos >= 360) {} else {
            sw_done = true;
        }
    }
    return pos;
}

double Draw::get_radius_total() {
    return CHART_SIZE / 2;
}

Offset Draw::get_center_item(double size, Offset offset) {
    Offset res;
    res.x = offset.x - (size / 2);
    res.y = offset.y - (size / 2);
    return res;
}


Offset Draw::get_pos_trigo(double angular, double radius_circle) {
    double center = Draw::get_radius_total();
    Offset res;
    res.x = center + cos(angular / 360 * 2 * M_PI) * -1 * radius_circle;
    res.y = center + sin(angular / 360 * 2 * M_PI) * radius_circle;
    return res;
}

Offset Draw::get_center() {
    Offset res;
    res.x = Draw::get_radius_total();
    res.y = Draw::get_radius_total();
}

Offset *Draw::get_line_trigo(double angular, double radius_circle_begin, double radius_circle_end) {
    Offset* res = new Offset[2];
    res[0].x = Draw::get_center().x + cos(angular / 360 * 2 * M_PI) * -1 * radius_circle_begin;
    res[0].y = Draw::get_center().y + sin(angular / 360 * 2 * M_PI) * radius_circle_begin;
    res[1].x = Draw::get_center().x + cos(angular / 360 * 2 * M_PI) * -1 * radius_circle_end;
    res[1].y = Draw::get_center().y + sin(angular / 360 * 2 * M_PI) * radius_circle_end;
    return res;
}

double Draw::get_astre_longitude(H house, CalcUt calcul_ut) {
    double pos = 360 - house.longitude + calcul_ut.longitude;
    pos = Draw::get_fixed_pos(pos);
    return pos;
}

double Draw::get_item_longitude(H house, double longitude) {
    double pos = 360 - house.longitude + longitude;
    pos = Draw::get_fixed_pos(pos);
    return pos;
}

Offset *Draw::get_triangle_trigo(double angular,
                                 double angular_pointer,
                                 double radius_circle_begin,
                                 double radius_circle_end) {
    Offset* res = new Offset[3];
    double angular1 = Draw::get_fixed_pos(angular - angular_pointer);
    double angular2 = Draw::get_fixed_pos(angular + angular_pointer);
    res[0].x = Draw::get_center().x + cos(angular1 / 360 * 2 * M_PI) * -1 * radius_circle_begin;
    res[0].y = Draw::get_center().y + sin(angular1 / 360 * 2 * M_PI) * radius_circle_begin;
    res[1].x = Draw::get_center().x + cos(angular2 / 360 * 2 * M_PI) * -1 * radius_circle_begin;
    res[1].y = Draw::get_center().y + sin(angular2 / 360 * 2 * M_PI) * radius_circle_begin;
    res[2].x = Draw::get_center().x + cos(angular / 360 * 2 * M_PI) * -1 * radius_circle_end;
    res[2].y = Draw::get_center().y + sin(angular / 360 * 2 * M_PI) * radius_circle_end;
    return res;
}

double Draw::get_sign_longitude(H house_asc, CalcUt calcul_ut) {
    double pos = 0;
    pos = 360 - house_asc.longitude + calcul_ut.longitude;
    return pos;
}

double Draw::get_angle_longitude(H* house, Angles angle) {
    double pos = 0;
    switch (angle) {
        case Angles::asc:
            pos = 360 - house[0].longitude + house[0].longitude;
            break;
        case Angles::fc:
            pos = 360 - house[0].longitude + house[3].longitude;
            break;
        case Angles::desc:
            pos = 360 - house[0].longitude + house[6].longitude;
            break;
        case Angles::mc:
            pos = 360 - house[0].longitude + house[9].longitude;
            break;
        case Angles::nothing:
            break;
    }
    pos = Draw::get_fixed_pos(pos);
    return pos;
}

double Draw::get_z_norm(double angle) {
    double a = remainder(angle, 360);
    if (a <= (360/ 2)) {
        return a;
    } else {
        return a - 360;
    }
}

double Draw::get_closest_distance(double *angle) {
    return Draw::get_z_norm(angle[1] - angle[0]);
}
