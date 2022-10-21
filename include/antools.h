#ifndef ANTOOLS_LIBRARY_H
#define ANTOOLS_LIBRARY_H

#include <iostream>
#include "../other_cmake/Swe/Swe.h"
#include "../other_cmake/SweInterface/SweInterface.h"

struct BB64 {
    const char* b_64;
    bool sw;
    const char* err;
};

extern "C" BB64 theme_astral(int year,
                            int month,
                            int day,
                            int hour,
                            int min,
                            double lat,
                            double lng,
                            int tz,
                            const char* ephem_path);

#endif //ANTOOLS_LIBRARY_H