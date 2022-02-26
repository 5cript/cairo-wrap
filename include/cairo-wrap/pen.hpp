#pragma once

#include "draw_context.hpp"

namespace Cairo
{
    struct Pen
    {
        double width;
        RGBA color;

        constexpr Pen(Pen const&) = default;
        constexpr Pen(Pen&&) = default;

        Pen& operator=(Pen const&) = default;
        Pen& operator=(Pen&&) = default;

        Pen& operator=(RGBA const& color);
        Pen() = default;

        constexpr Pen(double width, RGBA color)
            : width{width}
            , color{std::move(color)}
        {
        }
        constexpr Pen(RGBA color)
            : width{1}
            , color{std::move(color)}
        {
        }
        constexpr Pen(RGB color)
            : width{1}
            , color{color}
        {
        }
    };

    #define PRESERVE true

    void applyPen(DrawContext* ctx, Pen const& pen);
    void stroke(DrawContext* ctx, Pen const& pen, bool preserve = false);
    void fill(DrawContext* ctx, Pen const& pen, bool preserve = false);
}
