#pragma once

#include "core.hpp"

#include <string>

namespace Cairo
{
    struct Font
    {
        std::string family = "Arial";
        double size = 12;
        cairo_font_slant_t slant = CAIRO_FONT_SLANT_NORMAL;
        cairo_font_weight_t weight = CAIRO_FONT_WEIGHT_NORMAL;
    };
}
