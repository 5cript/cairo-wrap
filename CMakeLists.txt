# Version check
cmake_minimum_required(VERSION 3.11)

# Project
project(cairo-wrap)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
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
endif()

# Add library
add_library(cairo-wrap STATIC 
	"src/cairo-wrap/arc.cpp" 
	"src/cairo-wrap/arrow.cpp"
	"src/cairo-wrap/draw_context.cpp"
	"src/cairo-wrap/line.cpp"
	"src/cairo-wrap/path.cpp"
	"src/cairo-wrap/pen.cpp"
	"src/cairo-wrap/rectangle.cpp"
	"src/cairo-wrap/round_rectangle.cpp"
	"src/cairo-wrap/shape.cpp"
	"src/cairo-wrap/surface.cpp"
	"src/cairo-wrap/text.cpp"
)

target_include_directories(cairo-wrap PUBLIC include)

target_link_libraries(cairo-wrap PUBLIC cairo)

# Compiler Options
target_compile_options(cairo-wrap PRIVATE -fexceptions -std=c++14 -O3 -Wall -pedantic-errors -pedantic)
