#pragma once

#include "shape.hpp"

namespace Cairo
{
    class Rectangle : public Shape
    {
    public:
        Rectangle(DrawContext* ctx, double x = 0., double y = 0., double width = 0., double height = 0.);
        void draw(Pen const& line, Pen const& fill) override;

    protected:
        double width_;
        double height_;
    };
}
