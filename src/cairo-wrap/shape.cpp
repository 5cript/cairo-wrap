#include <cairo-wrap/shape.hpp>

namespace Cairo
{
    Shape::Shape(DrawContext* ctx, double x, double y)
        : ctx_(ctx)
        , x_{x}
        , y_{y}
    {

    }
    void Shape::move(double x, double y) noexcept
    {
        x_ = x;
        y_ = y;
    }
}
