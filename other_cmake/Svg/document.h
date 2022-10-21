//
// Created by Stéphane on 04.10.22.
//

#ifndef ANTOOLS_EXE_DOCUMENT_H
#define ANTOOLS_EXE_DOCUMENT_H

#include <iostream>
#include "svg.h"

using namespace std;

class Document
{
private:
    float width;
    float height;
    string content;
public:
    Document(float w, float h);
    Document & operator<<(string const & s) {
        content += s;
        return *this;
    }
    string generate();
};

#endif //ANTOOLS_EXE_DOCUMENT_H
