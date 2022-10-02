cmake_minimum_required(VERSION 3.22)

project(SweInterface)

set(CMAKE_CXX_STANDARD 20)

set( SOURCES
        angle.cpp
        aspect.cpp
        astre.cpp
        draw.cpp
        draw_aspect_line.cpp
        draw_bodie_astre.cpp
        draw_bodie_line.cpp
        draw_house_angle.cpp
        draw_house_line.cpp
        draw_house_number.cpp
        draw_zodiac_circle.cpp
        draw_zodiac_line.cpp
        draw_zodiac_sign.cpp
        swe02.cpp
        swe03.cpp
        swe08.cpp
        swe14.cpp
        swe17.cpp
        house.cpp
        sign.cpp
        timezone.cpp
        SweInterface.cpp)

include_directories( BEFORE . )

add_library(SweInterface STATIC ${SOURCES})