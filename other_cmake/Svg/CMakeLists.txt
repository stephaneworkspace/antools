cmake_minimum_required(VERSION 3.22)

project(Svg)

set(CMAKE_CXX_STANDARD 20)

set( SOURCES
        svg_data.cpp svg.h)

include_directories( BEFORE . )

add_library(Svg STATIC ${SOURCES})