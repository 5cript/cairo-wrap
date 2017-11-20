# Version check
cmake_minimum_required (VERSION 3.0)

set(cairo-wrap "cairo_wrap")

# Project
project(cairo-wrap)

# Add files
file(GLOB sources "*.cpp")

# Add library
add_library(${cairo-wrap} STATIC ${sources})

target_link_libraries(${cairo-wrap} cairo)

# Compiler Options
target_compile_options(${cairo-wrap} PUBLIC -fexceptions -std=c++14 -O3 -Wall -pedantic-errors -pedantic)