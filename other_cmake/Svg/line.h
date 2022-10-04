//
// Created by Stéphane on 04.10.22.
//

#ifndef ANTOOLS_EXE_LINE_H
#define ANTOOLS_EXE_LINE_H

#include <iostream>
#include "../../include/antools.h"
#include "svg.h"

using namespace std;

class Line
{
private:
    SvgStroke stroke;
public:
    Line(Stroke s);
    void set_stroke(Stroke s);
    string generate(float x1, float y1, float x2, float y2);
};

#endif //ANTOOLS_EXE_LINE_H
