# Swisseph CMakeLists.txt
cmake_minimum_required( VERSION 2.8 )
project( cswisseph )
message( STATUS "-- Configuring cswisseph..." )
set( SOURCES
    swecl.c
    swedate.c
    swehel.c
    swehouse.c
    swejpl.c
    swemmoon.c
    swemplan.c
    #swemptab.c
    swepcalc.c
    sweph.c
    swephlib.c
    )
include_directories( BEFORE . )
#add_definitions(-g -O9 -Wall)
add_library( swe STATIC ${SOURCES} )