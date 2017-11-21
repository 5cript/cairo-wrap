#include "arrow.hpp"

#include <cmath>

#define M_PI 3.14159265358979323846264338327950288

namespace Cairo
{
//#####################################################################################################################
    Arrow::Arrow(DrawContext* ctx, double x, double y, double x2, double y2, double arrowDegree, double arrowLength)
        : Line{ctx, x, y, x2, y2}
        , arrowDegree_{arrowDegree}
        , arrowLength_{arrowLength}
    {

    }
//---------------------------------------------------------------------------------------------------------------------
    void Arrow::draw(Pen const& line, Pen const& fill)
    {
        Line::draw(line);

        double angle = atan2 (y2_ - y_, x2_ - x_) + M_PI;

        auto x1 = x2_ + arrowLength_ * cos(angle - arrowDegree_);
        auto y1 = y2_ + arrowLength_ * sin(angle - arrowDegree_);
        auto x2 = x2_ + arrowLength_ * cos(angle + arrowDegree_);
        auto y2 = y2_ + arrowLength_ * sin(angle + arrowDegree_);

        cairo_move_to(*ctx_, x2_, y2_);
        cairo_line_to(*ctx_, x1, y1);
        stroke(ctx_, fill);

        cairo_move_to(*ctx_, x2_, y2_);
        cairo_line_to(*ctx_, x2, y2);
        stroke(ctx_, fill);
    }
//#####################################################################################################################
}
