//
// Created by Stéphane on 04.10.22.
//
#include "circle.h"

SCircle::SCircle(SFill fill, SStroke stroke) {
    properties.fill.fill = fill.fill.c_str();
    properties.stroke.stroke = stroke.stroke.c_str();
    properties.stroke.stroke_width = stroke.stroke_width;
}

string SCircle::generate(float x, float y, float r) {
    const char* res = svg_circle(x, y, r, properties);
    string s;
    s.assign(res);
    return s;
}