#include "round_rectangle.hpp"

#include <cmath>

#ifndef M_PI
#   define M_PI 3.14159265358979323846264338327950288
#endif

namespace Cairo
{
    RoundRectangle::RoundRectangle(DrawContext* ctx, double x, double y, double width, double height, double radius)
        : Rectangle{ctx, x, y, width, height}
        , radius_{radius}
    {

    }
    void RoundRectangle::draw(Pen const& line, Pen const& fill)
    {
        double degrees = M_PI / 180.;

        cairo_new_sub_path(*ctx_);
        cairo_arc (*ctx_, x_ + width_ - radius_, y_ + radius_, radius_, -90 * degrees, 0 * degrees);
        cairo_arc (*ctx_, x_ + width_ - radius_, y_ + height_ - radius_, radius_, 0 * degrees, 90 * degrees);
        cairo_arc (*ctx_, x_ + radius_, y_ + height_ - radius_, radius_, 90 * degrees, 180 * degrees);
        cairo_arc (*ctx_, x_ + radius_, y_ + radius_, radius_, 180 * degrees, 270 * degrees);
        cairo_close_path (*ctx_);

        Cairo::fill(ctx_, fill, PRESERVE);
        Cairo::stroke(ctx_, line);
    }
}
