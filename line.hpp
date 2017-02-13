#pragma once

#include "shape.hpp"

namespace Cairo
{
    class Line : public Shape
    {
    public:
        Line(DrawContext* ctx, double x, double y, double x2, double y2);

        void draw(Pen const& line, Pen const& fill = {}) override;

    private:
        double x2_;
        double y2_;
    };
}
