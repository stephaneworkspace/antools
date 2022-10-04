//
// Created by Stéphane on 04.10.22.
//

#include "line.h"

Line::Line(Stroke s) {
    stroke.stroke = s.stroke.c_str();
    stroke.stroke_width = s.stroke_width;
}

string Line::generate(float x1, float y1, float x2, float y2) {
    const char* res = svg_line(x1, y1, x2, y2, stroke);
    string s;
    s.assign(res);
    return s;
}