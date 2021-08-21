# Version check
cmake_minimum_required(VERSION 3.11)

# Default CXX Standard
if (NOT "${CMAKE_CXX_STANDARD}")
	set(CMAKE_CXX_STANDARD 17)
endif()

# Default Build Type
if (NOT EXISTS ${CMAKE_BINARY_DIR}/CMakeCache.txt)
	if (NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
	endif()
endif()

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
