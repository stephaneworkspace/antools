//
// Created by Stéphane on 30.09.22.
//
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/antools.h"
#include "../other_cmake/SweInterface/base64.h"
#include "svg_data.h"

using namespace std;

int main() {
    /*
    string path_string_log = filesystem::current_path().parent_path().parent_path();
    string log_output = path_string_log + "/output.txt";
    string log_error = path_string_log + "/error.txt";
    const char* log_output_p = log_output.data();
    const char* log_error_p = log_error.data();
    log_app(log_output_p, log_error_p);
    */

    // Svg
    Data data = Data();
    data.move_to("10.0,10.0");
    data.line_by("0.56,50.0");
    data.line_by("50,5.10");
    data.line_by("0.59,-50");
    data.close_by();
    data.create_svg();


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