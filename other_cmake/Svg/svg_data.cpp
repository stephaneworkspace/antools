//
// Created by Stéphane on 03.10.22.
//
#include "svg_data.h"

int Data::get_size(string s) {
    return std::count(s.begin(), s.end(), DELIMITER_CHAR) + 1;
}

float Data::get_value(std::string s, int pos) {
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

SvgPoint Data::set_point(std::string point_string, int pos) {
    SvgPoint point;
    point.point_idx = idx_data;
    point.point = get_value(point_string, pos);
    return point;
}

void Data::set_command(char c, string s) {
    int size = get_size(s);
    vec_data.push_back(Data::set_data(c, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(Data::set_point(s, k));
    }
    idx_data++;
    idx_point += size;
}

Data::Data() {
    idx_data = 0;
    idx_point = 0;
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

void Data::create_svg() {
    SvgData* data = vec_data.data();
    SvgPoint* point = vec_point.data();
    string p = filesystem::current_path().parent_path().parent_path();
    p += "/temp/svg_rust.svg";
    const char* path = p.c_str();
    const char* res = svg_rust(data, point, idx_data, idx_point, path);
    string s;
    s.assign(res);
    cout << s << endl;
}