#include "../include/antools.h"

extern "C" B64 theme_astral(int year, int month, int day, int hour, int min, double lat, double lng, int tz) {
    B64 res;
    res.b_64 = theme_astral_svg(year, month, day, hour, min, lat, lng, tz, "");
    return res;
}