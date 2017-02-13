#pragma once

#include "core.hpp"

#include <string>

namespace Cairo
{
    class Surface
    {
    public:
        Surface(int width, int height);
        ~Surface();

        operator cairo_surface_t*() {
            return surface_;
        }

        void saveToFile(std::string const& fileName);

    private:
        cairo_surface_t* surface_;
    };
}
