//
// Created by Stéphane on 04.10.22.
//
#include "circle.h"

Circle::Circle(Fill fill, Stroke stroke) {
    properties.fill.fill = fill.fill.c_str();
    properties.stroke.stroke = stroke.stroke.c_str();
    properties.stroke.stroke_width = stroke.stroke_width;
}

/*
string Circle::generate(float x, float y, float r) {
    const char* res = svg_circle(x, y, r, properties);
    string s;
    s.assign(res);
    return s;
}*/

string Circle::generate(float x, float y, float r) {
    string fill;
    fill.assign(properties.fill.fill);
    string stroke;
    stroke.assign(properties.stroke.stroke);
    string s = "<circle cx=\"" + to_string((int) x) + "\" cy=\"" + to_string((int) y) + "\" fill=\"" + fill + "\" r=\""+ to_string((int) r) +"\" stroke=\""+ stroke +"\" stroke-width=\""+ to_string((int) properties.stroke.stroke_width) +"\"/>";
    return s;
}
