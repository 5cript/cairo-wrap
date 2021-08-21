# Version Check
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

# Project
project(cairo-wrap)

# Add Files
file(GLOB sources "*.cpp")

# Add Executable
add_library(cairo_wrap STATIC ${sources})

target_link_libraries(cairo_wrap -lcairo)

# Compiler Options
set(DEBUG_OPTIONS -fexecptions -g -Wall -pedantic-errors -pedantic)
target_compile_options(cairo_wrap PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")

set(RELEASE_OPTIONS -fexceptions -O3 -Wall -pedantic)
target_compile_options(cairo_wrap PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")