#include "../include/antools.h"

extern "C" B64 theme_astral(int year, int month, int day, int hour, int min, double lat, double lng, int tz) {
    B64 res;
    res.b_64 = theme_astral_svg(year, month, day, hour, min, lat, lng, tz, "");
    return res;
}

/*
extern "C" void log_app(const char* output, const char* error) {
    freopen(output, "w", stdout);
    freopen(error, "w", stderr);

    cout << "Output message" << endl;
    cerr << "Error message" << endl;
}*/