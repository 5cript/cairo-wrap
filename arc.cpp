#include "arc.hpp"

namespace Cairo
{
//#####################################################################################################################
    Arc::Arc(DrawContext* ctx, double x, double y, double radius, double angleStart, double angleEnd)
        : Shape{ctx, x, y}
        , radius_{radius}
        , startAngle_{angleStart}
        , endAngle_{angleEnd}
    {
    }
//---------------------------------------------------------------------------------------------------------------------
    void Arc::draw(Pen const& line, Pen const& fill)
    {
        cairo_new_sub_path(*ctx_);
        cairo_arc(*ctx_, x_, y_, radius_, startAngle_, endAngle_);

        Cairo::fill(ctx_, fill, PRESERVE);
        Cairo::stroke(ctx_, line);
    }
//---------------------------------------------------------------------------------------------------------------------
    double Arc::toRadian(double degree) noexcept
    {
        return (degree * internal::pi) / 180.;
    }
//#####################################################################################################################
}
