//
// Created by Stéphane on 03.10.22.
//
#include "data.h"

long Data::get_size(string s) {
    return std::count(s.begin(), s.end(), DELIMITER_CHAR) + 1;
}

float Data::get_value(string s, int pos) {
    string c = DELIMITER;
    string res = "";
    auto start = 0U;
    auto end = s.find(c);
    int i = 0;
    while (end != string::npos)
    {
        if (pos == i) {
            //std::cout << s.substr(start, end - start) << std::endl;
            res = s.substr(start, end - start);
            float res_int = stof(res);
            return res_int;
        }
        i++;
        start = end + c.length();
        end = s.find(c, start);
    }
    if (pos == i) {
        //std::cout << s.substr(start, end) << std::endl;
        res = s.substr(start, end);
        float res_int = stof(res);
        return res_int;
    }
    return 0;
}

SvgData Data::set_data(char c, int point_size) {
    SvgData data;
    data.point_idx = idx_data;
    data.point_size = point_size;
    data.data = c;
    return data;
}

SvgPoint Data::set_point(string point_string, int pos) {
    SvgPoint point;
    point.point_idx = idx_data;
    point.point = get_value(point_string, pos);
    return point;
}

void Data::set_command(char c, string s) {
    long size = get_size(s);
    vec_data.push_back(Data::set_data(c, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(Data::set_point(s, k));
    }
    idx_data++;
    idx_point += size;
}

string Data::round(float var){
    // we use array of chars to store number
    // as a string.
    char str[40];

    // Print in string the value of var
    // with two decimal point
    sprintf(str, "%.1f", var);

    // scan string value in var
    sscanf(str, "%f", &var);

    return str;
}

Data::Data(Fill fill, Stroke stroke) {
    idx_data = 0;
    idx_point = 0;
    properties.fill.fill = fill.fill.c_str();
    properties.stroke.stroke = stroke.stroke.c_str();
    properties.stroke.stroke_width = stroke.stroke_width;
}

void Data::move_to(float x, float y) {
    char c = 'M';
    Data::set_command(c, to_string(x) + "," + to_string(y));
}

void Data::move_by(float x, float y) {
    char c = 'm';
    Data::set_command(c, to_string(x) + "," + to_string(y));
}

void Data::line_to(float x, float y) {
    char c = 'L';
    Data::set_command(c, to_string(x) + "," + to_string(y));
}

void Data::line_by(float x, float y) {
    char c = 'l';
    Data::set_command(c, to_string(x) + "," + to_string(y));
}

void Data::close_to() {
    char c = 'Z';
    vec_data.push_back(Data::set_data(c, 0));
    idx_data++;
}

void Data::close_by() {
    char c = 'z';
    vec_data.push_back(Data::set_data(c, 0));
    idx_data++;
}
/*
string Data::generate() {
    SvgData* data = vec_data.data();
    SvgPoint* point = vec_point.data();
    const char* res = svg_path_data(data, point, idx_data, idx_point, properties);
    string s;
    s.assign(res);
    return s;
}*/

string Data::generate() {
    string fill;
    fill.assign(properties.fill.fill);
    string stroke;
    stroke.assign(properties.stroke.stroke);
    string d;

    int l = 0;
    for (int i = 0; i < idx_data; ++i) {
        if (l > 0) {
            d += " ";
        }
        d += vec_data[i].data;
        int k = 0;
        for (int j = 0; j < idx_point; ++j) {
            if (vec_point[j].point_idx == vec_data[i].point_idx) {
                if (k > 0) {
                    d += ",";
                }
                if ((int) vec_point[j].point == vec_point[j].point ) {
                    d += to_string((int) vec_point[j].point);
                } else {
                    d += Data::round(vec_point[j].point);
                }
                k++;
            }
        }
        l++;
    }

    string s = "<path d=\"" + d + "\" fill=\"" + fill + "\" stroke=\""+ stroke +"\" stroke-width=\""+ to_string((int) properties.stroke.stroke_width) +"\"/>";
    return s;
}
