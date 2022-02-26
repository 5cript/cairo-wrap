#pragma once

#include "rectangle.hpp"

namespace Cairo
{
    class RoundRectangle : public Rectangle
    {
    public:
        RoundRectangle(DrawContext* ctx, double x = 0., double y = 0., double width = 0., double height = 0., double radius = 0.);
        void draw(Pen const& line, Pen const& fill) override;

    protected:
        double radius_;
    };

}
