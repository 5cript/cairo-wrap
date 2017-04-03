#pragma once

#include "draw_context.hpp"
#include "pen.hpp"

namespace Cairo
{
    class Shape
    {
    public:
        Shape(DrawContext* ctx, double x = 0., double y = 0.);
        virtual ~Shape() = default;
        virtual void draw(Pen const& line = {}, Pen const& fill = {}) = 0;
        void move(double x, double y) noexcept;

    protected:
        DrawContext* ctx_;
        double x_;
        double y_;
    };
}
