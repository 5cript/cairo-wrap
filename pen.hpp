#pragma once

#include "draw_context.hpp"

namespace Cairo
{
    struct Pen
    {
        double width;
        RGBA color;

        Pen& operator=(Pen const&) = default;
        Pen& operator=(Pen&&) = default;

        Pen& operator=(RGBA const& color);
        Pen() = default;
        Pen(double width, RGBA color);
        Pen(RGBA color);
        Pen(RGB color);
    };

    #define PRESERVE true

    void applyPen(DrawContext* ctx, Pen const& pen);
    void stroke(DrawContext* ctx, Pen const& pen, bool preserve = false);
    void fill(DrawContext* ctx, Pen const& pen, bool preserve = false);
}
