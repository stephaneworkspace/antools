cmake_minimum_required(VERSION 3.22)
project(antools_exe)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_SOURCE_DIR}/../other_cmake/Svg subproject/Svg)
add_subdirectory(${CMAKE_SOURCE_DIR}/../other_cmake/Swe subproject/Swe)
add_subdirectory(${CMAKE_SOURCE_DIR}/../other_cmake/SweInterface subproject/SweInterface)

include_directories(include)
file(GLOB SOURCES "../src/*.cpp")
add_executable(antools_exe
        main.cpp
        ../include/antools.h
        ../src/antools.cpp
        ../other_cmake/Svg/circle.h
        ../other_cmake/Svg/circle.cpp
        ../other_cmake/Svg/data.h
        ../other_cmake/Svg/data.cpp
        ../other_cmake/SweInterface/SweInterface.h
        ../other_cmake/SweInterface/SweInterface.cpp)
target_link_libraries(antools_exe ${CMAKE_SOURCE_DIR}/../rust/lib/librantools.a)
target_link_libraries(antools_exe Svg)
target_link_libraries(antools_exe swe)
target_link_libraries(antools_exe SweInterface)