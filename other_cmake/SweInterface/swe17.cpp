//
// Created by Stéphane on 22.09.22.
//
#include "swe17.h"
#include "sign.h"

SplitDeg Swe17::split_deg(double ddeg, int roundflag) {
    double sign_calc = floor(ddeg / 30.0);
    double house_calc = floor(ddeg / 30.0);
    double long30 = (house_calc * 30) - ddeg;
    int* deg_ptr = new int[1];
    int* min_ptr = new int[1];
    int* sec_ptr = new int[1];
    double* cdeg_ptr = new double[1];
    int* isgn_ptr = new int[1];
    double result = swe_split_deg(long30, roundflag, deg_ptr, min_ptr, sec_ptr, cdeg_ptr, isgn_ptr);
    string print = to_string(abs(deg_ptr[0])) + "°"
                 + to_string(abs(min_ptr[0])) + "'"
                 + to_string(abs(sec_ptr[0])) + "\"";
    Signs sign = Signs::belier;
    for (int i = 0; i < 12; ++i) {
        Signs sign_temp = static_cast<Signs>(sign_calc);
        if (i == int(sign_temp)) {
            sign = sign_temp;
            break;
        }
    }
    SplitDeg res;
    res.print = print;
    res.deg = deg_ptr[0];
    res.min = min_ptr[0];
    res.sec = sec_ptr[0];
    res.cdegfr = cdeg_ptr[0];
    res.sign = sign;
    res.result = result;
    free(deg_ptr);
    free(min_ptr);
    free(sec_ptr);
    free(cdeg_ptr);
    free(isgn_ptr);
    return res;
}

