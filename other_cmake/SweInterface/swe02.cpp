//
// Created by Stéphane on 22.09.22.
//
#include "swe02.h"

void Swe02::set_ephe_path(string path) {
    char* path_p = new char[255];
    std::strcpy(path_p, path.c_str());
    swe_set_ephe_path(path_p);
}

void Swe02::close() {
    swe_close();
}

string Swe02::version() {
    char* version = (char*)malloc(255);
    swe_version(version);
    string res = version;
    free(version);
    return res;
}

string Swe02::get_library_path() {
    char* path = (char*)malloc(255);
    swe_get_library_path(path);
    string res = path;
    free(path);
    return res;
}

