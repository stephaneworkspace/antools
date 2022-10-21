//
// Created by Stéphane on 01.10.22.
//

#ifndef ANTOOLS_EXE_SWEINTERFACE_H
#define ANTOOLS_EXE_SWEINTERFACE_H

#include <string>

#include "swe02.h"

using namespace std;

extern "C" const char* theme_astral_svg(int year, int month, int day, int hour, int min, double lat, double lng, int gmt, const char* ephem_path);

#endif //ANTOOLS_EXE_SWEINTERFACE_H
