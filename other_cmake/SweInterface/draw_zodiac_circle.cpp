//
// Created by Stéphane on 22.09.22.
//
#include "draw_zodiac_circle.h"

CirclePosition DrawCircle::get_radius_circle(CirclePositions circle_position) {
    CirclePosition res;
    switch (circle_position) {
        case zero:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_0.pcent / 100;
            res.sw = CIRCLE_SIZE_0.sw;
            break;
        case un:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_1.pcent / 100;
            res.sw = CIRCLE_SIZE_1.sw;
            break;
        case deux:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_2.pcent / 100;
            res.sw = CIRCLE_SIZE_2.sw;
            break;
        case trois:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_3.pcent / 100;
            res.sw = CIRCLE_SIZE_3.sw;
            break;
        case quatre:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_4.pcent / 100;
            res.sw = CIRCLE_SIZE_4.sw;
            break;
        case cinq:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_5.pcent / 100;
            res.sw = CIRCLE_SIZE_5.sw;
            break;
        case six:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_6.pcent / 100;
            res.sw = CIRCLE_SIZE_6.sw;
            break;
        case sept:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_7.pcent / 100;
            res.sw = CIRCLE_SIZE_7.sw;
            break;
        case huit:
            res.pcent = Draw::get_radius_total() * CIRCLE_SIZE_8.pcent / 100;
            res.sw = CIRCLE_SIZE_8.sw;
            break;
    }
    return res;
}

CircleZod DrawCircle::circle(CirclePositions circle_position) {
    CircleZod res;
    double center = Draw::get_radius_total();
    CirclePosition radius = DrawCircle::get_radius_circle(circle_position);
    res.center = center;
    res.radius = radius.pcent;
    res.sw = radius.sw;
    return res;
}



