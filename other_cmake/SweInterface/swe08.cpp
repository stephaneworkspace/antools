//
// Created by Stéphane on 22.09.22.
//
#include "swe08.h"

UtcToJd Swe08::utc_to_jd(TimeZone tz, Calandar calandar) {
    double* dret_ptr = new double[2];
    char* serr_ptr = new char[255];
    int result = swe_utc_to_jd(tz.year, tz.month, tz.day, tz.hour, tz.min, tz.sec, int(calandar), dret_ptr, serr_ptr);
    UtcToJd res;
    res.julian_day_et = dret_ptr[0];
    res.julian_day_ut = dret_ptr[1];
    res.err = serr_ptr;
    res.result = result;
    free(dret_ptr);
    free(serr_ptr);
    return res;
}

