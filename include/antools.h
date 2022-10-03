#ifndef ANTOOLS_LIBRARY_H
#define ANTOOLS_LIBRARY_H

#include <iostream>
#include "../other_cmake/Swe/Swe.h"
#include "../other_cmake/SweInterface/SweInterface.h"

// ./rust

struct B64 {
    const char* b_64;
    bool sw;
    const char* err;
};

struct SvgData {
    char data;
    int point_idx;
    int point_size;
};

struct SvgPoint {
    int point_idx;
    float point;
};

// ./src

extern "C" B64 theme_astral(int year, int month, int day, int hour, int min, double lat, double lng, int tz);
//extern "C" void log_app(const char* output, const char* error);

// ./rust

extern "C" B64 create_png_b64(const char* p_svg_b64);
extern "C" B64 create_pdf_b64(const char* p_svg_b64);
extern "C" const char* svg_rust(const SvgData* data,
                                const SvgPoint* point,
                                int data_size,
                                int point_size,
                                const char* path);

#endif //ANTOOLS_LIBRARY_H
