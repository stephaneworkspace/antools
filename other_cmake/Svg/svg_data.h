//
// Created by Stéphane on 03.10.22.
//

#ifndef ANTOOLS_EXE_SVG_DATA_H
#define ANTOOLS_EXE_SVG_DATA_H

#include <fstream>
#include <iostream>
#include <vector>
#include "../../include/antools.h"

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
    static int get_size(string s);
    static float get_value(std::string s, int pos);
    SvgData set_data(char c, int point_size);
    SvgPoint set_point(std::string point_string, int pos);
    void set_command(char c, string s);
public:
    Data();
    void move_to(string s);
    void move_by(string s);
    void line_to(string s);
    void line_by(string s);
    void close_to();
    void close_by();
    void create_svg();
};

#endif //ANTOOLS_EXE_SVG_DATA_H
