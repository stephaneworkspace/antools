//
// Created by Stéphane on 04.10.22.
//
#include "image.h"

string SImage::generate(float height, float width, float x, float y, const char* href) {
    const char* res = svg_image(height, width, x, y, href);
    string s;
    s.assign(res);
    return s;
}