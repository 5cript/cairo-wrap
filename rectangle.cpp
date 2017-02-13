#include "rectangle.hpp"

namespace Cairo
{
    Rectangle::Rectangle(DrawContext* ctx, double x, double y, double width, double height)
        : Shape{ctx, x, y}
        , width_{width}
        , height_{height}
    {

    }
    void Rectangle::draw(Pen const& line, Pen const& fill)
    {
        cairo_rectangle(*ctx_, x_, y_, width_, height_);
        Cairo::fill(ctx_, fill, PRESERVE);
        Cairo::stroke(ctx_, line);
    }
}
