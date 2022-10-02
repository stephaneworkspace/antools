//
// Created by Stéphane on 22.09.22.
//
#include "swe07.h"

PhenoUt Swe07::calc_ut(double tjd_ut, Astres ipl, OptionFlag iflag) {
    double* attr_ptr = new double[20];
    char* serr_ptr = new char[255];
    int status = swe_pheno_ut(tjd_ut ,int(ipl), int(iflag), attr_ptr, serr_ptr);
    PhenoUt res;
    res.phase_angle = attr_ptr[0];
    res.phase_illuminated = attr_ptr[1];
    res.elongation_of_planet = attr_ptr[2];
    res.apparent_diameter_of_disc = attr_ptr[3];
    res.apparent_magnitude = attr_ptr[4];
    res.status = int(status);
    res.serr = serr_ptr;
    free(attr_ptr);
    free(serr_ptr);
    return res;
}