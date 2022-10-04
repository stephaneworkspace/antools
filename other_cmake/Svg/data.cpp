//
// Created by Stéphane on 03.10.22.
//
#include "data.h"

int SData::get_size(string s) {
    return std::count(s.begin(), s.end(), DELIMITER_CHAR) + 1;
}

float SData::get_value(string s, int pos) {
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

SvgData SData::set_data(char c, int point_size) {
    SvgData data;
    data.point_idx = idx_data;
    data.point_size = point_size;
    data.data = c;
    return data;
}

SvgPoint SData::set_point(string point_string, int pos) {
    SvgPoint point;
    point.point_idx = idx_data;
    point.point = get_value(point_string, pos);
    return point;
}

void SData::set_command(char c, string s) {
    int size = get_size(s);
    vec_data.push_back(SData::set_data(c, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(SData::set_point(s, k));
    }
    idx_data++;
    idx_point += size;
}

SData::SData(SFill fill, SStroke stroke) {
    idx_data = 0;
    idx_point = 0;
    properties.fill.fill = fill.fill.c_str();
    properties.stroke.stroke = stroke.stroke.c_str();
    properties.stroke.stroke_width = stroke.stroke_width;
}

void SData::move_to(float x, float y) {
    char c = 'M';
    SData::set_command(c, to_string(x) + "," + to_string(y));
}

void SData::move_by(float x, float y) {
    char c = 'm';
    SData::set_command(c, to_string(x) + "," + to_string(y));
}

void SData::line_to(float x, float y) {
    char c = 'L';
    SData::set_command(c, to_string(x) + "," + to_string(y));
}

void SData::line_by(float x, float y) {
    char c = 'l';
    SData::set_command(c, to_string(x) + "," + to_string(y));
}

void SData::close_to() {
    char c = 'Z';
    vec_data.push_back(SData::set_data(c, 0));
    idx_data++;
}

void SData::close_by() {
    char c = 'z';
    vec_data.push_back(SData::set_data(c, 0));
    idx_data++;
}

string SData::generate() {
    SvgData* data = vec_data.data();
    SvgPoint* point = vec_point.data();
    const char* res = svg_path_data(data, point, idx_data, idx_point, properties);
    string s;
    s.assign(res);
    return s;
}