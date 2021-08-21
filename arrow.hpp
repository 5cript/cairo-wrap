#pragma once

#include "line.hpp"

namespace Cairo
{
    class Arrow : public Line
    {
    public:
        Arrow(DrawContext* ctx, double x, double y, double x2, double y2, double arrowDegree = 0.5, double arrowLength = 8);

        void draw(Pen const& line, Pen const& fill = {}) override;

    protected:
        double arrowDegree_;
        double arrowLength_;
    };
}
