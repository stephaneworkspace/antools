//
// Created by Stéphane on 04.10.22.
//
#include "image.h"

/*
string Image::generate(float height, float width, float x, float y, const char* href) {
    const char* res = svg_image(width, height, x, y, href);
    string s;
    s.assign(res);
    return s;
}*/

string Image::generate(float height, float width, float x, float y, const char* href) {
    string h;
    h.assign(href);
    string s = "<image height=\""+ to_string((int) height) + "\" href=\"" + h + "\" width=\"" + to_string((int) width) + "\" x=\"" + to_string((int) x) + "\" y=\"" + to_string((int) y) + "\"/>";
    return s;
}
