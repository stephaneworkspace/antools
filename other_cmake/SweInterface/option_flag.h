//
// Created by Stéphane on 22.09.22.
//

#ifndef ASTRONUMEROLOGIE_GENERATE_OPTION_FLAG_H
#define ASTRONUMEROLOGIE_GENERATE_OPTION_FLAG_H
enum OptionFlag {
    jpl_eph = 1,
    swiss_eph = 2,
    moshier = 4,
    heliocentric = 8,
    true_position = 16,
    j2000_equinox = 32,
    no_nutation = 64,
    speed3 = 128,
    speed = 256,
    no_gravitanional_deflection = 512,
    no_annual_aberration = 1024,
    astronomic_position = 1536,
    equatorial_position = 2048,
    x_y_z_cartesian_not_polar_coordinate = 4096,
    radians = 8192,
    barycentric_position = 16384,
    topocentric_position = 32768,
    sideral_position = 65536,
    i_CRS = 131072,
    dpsideps1980 = 262144,
    jpl_hor_approx = 524288
};
#endif //ASTRONUMEROLOGIE_GENERATE_OPTION_FLAG_H
