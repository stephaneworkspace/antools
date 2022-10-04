//
// Created by Stéphane on 30.09.22.
//
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/antools.h"
#include "../other_cmake/SweInterface/base64.h"
#include "../other_cmake/Svg/circle.h"
#include "../other_cmake/Svg/data.h"
#include "../other_cmake/Svg/line.h"

using namespace std;

int main() {
    // Data
    SFill fill;
    fill.fill = "none";
    SStroke stroke;
    stroke.stroke = "black";
    stroke.stroke_width = 3;
    SData data = SData(fill, stroke);
    data.move_to(10.0,10.0);
    data.line_by(0.50,50.0);
    data.line_by(50,0);
    data.line_by(0,-50);
    data.close_by();
    cout << data.generate() << endl;

    // Circle
    SCircle circle = SCircle(fill, stroke);
    cout << circle.generate(10,20,30) << endl;

    // Circle
    SLine line = SLine(stroke);
    cout << line.generate(10,20,30,40) << endl;

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

    return 0;
}