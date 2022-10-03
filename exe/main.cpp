//
// Created by Stéphane on 30.09.22.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "../include/antools.h"
#include "../other_cmake/SweInterface/base64.h"

using namespace std;

int get_size(std::string s, char c) {
    return std::count(s.begin(), s.end(), c);
}

// TODO try catch sinon Struct erreur
int get_value(std::string s, int pos) {
    std::string c = ";";
    auto start = 0U;
    auto end = s.find(c);
    int i = 0;
    while (end != std::string::npos)
    {
        if (pos == i) {
            //std::cout << s.substr(start, end - start) << std::endl;
            return std::stoi(s.substr(start, end - start));
        }
        i++;
        start = end + c.length();
        end = s.find(c, start);
    }
    if (pos == i) {
        //std::cout << s.substr(start, end) << std::endl;
        return std::stoi(s.substr(start, end));
    }
}

SvgData set_data(char c, int point_idx, int point_size) {
    SvgData data;
    data.point_idx = point_idx;
    data.point_size = point_size;
    data.data = c;
    return data;
}

SvgPoint set_point(int point_idx, std::string point_string, int pos) {
    SvgPoint point;
    point.point_idx = point_idx;
    point.point = get_value(point_string, pos);
    return point;
}

int svg2() {
    int i = 0;
    int j = 0;
    int size = 0;
    std::string s = "";
    char c = ' ';
    vector<SvgData> vec_data;
    vector<SvgPoint> vec_point;


    //
    c = 'M';
    s = "10;10;";
    size = get_size(s, ';');
    vec_data.push_back(set_data(c, i, size));
    for (int k = 0; k < size; ++k) {
       vec_point.push_back(set_point(i, s, k));
    }
    i++;
    j += size;

    //
    c = 'l';
    s = "0;50;";
    size = get_size(s, ';');
    vec_data.push_back(set_data(c, i, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(set_point(i, s, k));
    }
    i++;
    j += size;

    //
    c = 'l';
    s = "50;0;";
    size = get_size(s, ';');
    vec_data.push_back(set_data(c, i, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(set_point(i, s, k));
    }
    i++;
    j += size;

    //
    c = 'l';
    s = "0;-50;";
    size = get_size(s, ';');
    vec_data.push_back(set_data(c, i, size));
    for (int k = 0; k < size; ++k) {
        vec_point.push_back(set_point(i, s, k));
    }
    i++;
    j += size;

    //
    c = 'z';
    size = 0;
    vec_data.push_back(set_data(c, i, size));
    i++;
    j += size;

    SvgData* data = vec_data.data();
    SvgPoint* point = vec_point.data();
    /*
<svg viewBox="0 0 70 70" xmlns="http://www.w3.org/2000/svg">
<path d="M10,10 l0,50 l50,0 l0,-50 z" fill="none" stroke="black" stroke-width="3"/>
</svg>
     */

    string p = filesystem::current_path().parent_path().parent_path();
    p += "/temp/svg_rust.svg";
    const char* path = p.c_str();

    svg_rust(data, point, i, j, path);
}

int main() {
    /*
    string path_string_log = filesystem::current_path().parent_path().parent_path();
    string log_output = path_string_log + "/output.txt";
    string log_error = path_string_log + "/error.txt";
    const char* log_output_p = log_output.data();
    const char* log_error_p = log_error.data();
    log_app(log_output_p, log_error_p);
    */
    svg2();
    cout << "Hello, World!" << endl;

    // Créer un pdf du thème astral dans /temp/mypdf.pdf
    B64 ta = theme_astral(1984, 4, 1, 20, 30, 10, 60, 2);

    // temp/mysvg.svg
    string input_svg;
    input_svg.assign(ta.b_64);
    static string output_svg;
    if(!Base64::Decode(input_svg, &output_svg)) {
        std::cout << "Failed to decode input string" << std::endl;
        return 1;
    }
    string path_string_svg = filesystem::current_path().parent_path().parent_path();
    path_string_svg += "/temp/mysvg.svg";
    ofstream o;
    o.open(path_string_svg, ios::binary);
    o << output_svg;
    o.close();

    // temp/mypdf.pdf
    B64 ta_pdf = create_pdf_b64(ta.b_64);
    string input;
    input.assign(ta_pdf.b_64);
    static string output;
    if(!Base64::Decode(input, &output)) {
        std::cout << "Failed to decode input string" << std::endl;
        return 1;
    }

    if (ta_pdf.sw) {
        string path_string = filesystem::current_path().parent_path().parent_path();
        path_string += "/temp/mypdf.pdf";

        ofstream o;
        o.open(path_string, ios::binary);
        o << output;
        o.close();
    }

    // temp/mypng.png
    B64 ta_png = create_png_b64(ta.b_64);
    string input_png;
    input_png.assign(ta_png.b_64);
    static string output_png;
    if(!Base64::Decode(input_png, &output_png)) {
        std::cout << "Failed to decode input string" << std::endl;
        return 1;
    }

    if (ta_png.sw) {
        string path_string = filesystem::current_path().parent_path().parent_path();
        path_string += "/temp/mypng.png";

        ofstream o;
        o.open(path_string, ios::binary);
        o << output_png;
        o.close();
    }

    //const char* res = theme_astral_svg(1984, 1, 1, 0, 0, 0, 0, 2, "");
    //string s;
    //s.assign(res);
    //cout << s << endl;
    //string ss = "";
    //PdfB64 s = create_pdf_b64(ss.c_str());
    //cout << s.pdf_b_64 << endl;
    //cout << s.err << endl;
    //PdfB64 ta = theme_astral(1984,1,1,0,0,0,0,2);
    //cout << ta.pdf_b_64 << endl;
    //cout << ta.err << endl;
    return 0;
}