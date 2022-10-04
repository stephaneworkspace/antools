//
// Created by Stéphane on 03.10.22.
//

#ifndef ANTOOLS_EXE_DATA_H
#define ANTOOLS_EXE_DATA_H

#include <fstream>
#include <iostream>
#include <vector>
#include "../../include/antools.h"
#include "svg.h"

using namespace std;

const string DELIMITER = ",";
const char DELIMITER_CHAR = ',';

class Data
{
private:
    vector<SvgData> vec_data;
    vector<SvgPoint> vec_point;
    int idx_data;
    int idx_point;
    SvgProperties properties;
    static int get_size(string s);
    static float get_value(string s, int pos);
    SvgData set_data(char c, int point_size);
    SvgPoint set_point(string point_string, int pos);
    void set_command(char c, string s);
public:
    Data(SvgFill fill, SvgStroke stroke);
    void move_to(float x, float y);
    void move_by(float x, float y);
    void line_to(float x, float y);
    void line_by(float x, float y);
    void close_to();
    void close_by();
    string generate();
};

#endif //ANTOOLS_EXE_DATA_H
