//
// Created by Stéphane on 22.09.22.
//
#include "swe14.h"

H Swe14::house(double tjd_ut, double geo_lat, double geo_lng, char hsys, int house) {
    double* cusps_ptr = new double[37];
    double* ascmc_ptr = new double[10];
    int _ = swe_houses_ex(tjd_ut, 0, geo_lat, geo_lng, hsys, cusps_ptr, ascmc_ptr);
    angle angle = angle::nothing;
    if (house == 1) {
        angle = angle::asc;
    }
    if (house == 4) {
        angle = angle::fc;
    }
    if (house == 7) {
        angle = angle::desc;
    }
    if (house == 10) {
        angle = angle::mc;
    }
    H res = House::init(house, cusps_ptr[house], angle);
    free(cusps_ptr);
    free(ascmc_ptr);
    return res;
}

