//
// Created by Stéphane on 04.10.22.
//

#include "document.h"

SDocument::SDocument(float w, float h) {
    width = w;
    height = h;
    content = "";
}

string SDocument::generate() {
    const char* res = svg_document(width, height, content.c_str());
    string s;
    s.assign(res);
    return s;
}
