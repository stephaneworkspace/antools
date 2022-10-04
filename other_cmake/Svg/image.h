//
// Created by Stéphane on 04.10.22.
//

#ifndef ANTOOLS_EXE_IMAGE_H
#define ANTOOLS_EXE_IMAGE_H

#include <iostream>
#include "../../include/antools.h"
#include "svg.h"

using namespace std;

class SImage
{
public:
    static string generate(float height, float width, float x, float y, const char* href);
};

#endif //ANTOOLS_EXE_IMAGE_H
