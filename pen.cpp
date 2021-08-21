#include "pen.hpp"

namespace Cairo
{
//#####################################################################################################################
    Pen& Pen::operator=(RGBA const& color)
    {
        this->color = color;
        return *this;
    }
//#####################################################################################################################
    void applyPen(DrawContext* ctx, Pen const& pen)
    {
        cairo_set_line_width(*ctx, pen.width);
        cairo_set_source_rgba(
            *ctx,
            static_cast <double> (pen.color.r) / colorMax,
            static_cast <double> (pen.color.g) / colorMax,
            static_cast <double> (pen.color.b) / colorMax,
            static_cast <double> (pen.color.a) / colorMax
        );
    }
//---------------------------------------------------------------------------------------------------------------------
    void stroke(DrawContext* ctx, Pen const& pen, bool preserve)
    {
        applyPen(ctx, pen);
        if (preserve)
            cairo_stroke_preserve(*ctx);
        else
            cairo_stroke(*ctx);
    }
//---------------------------------------------------------------------------------------------------------------------
    void fill(DrawContext* ctx, Pen const& pen, bool preserve)
    {
        applyPen(ctx, pen);
        if (preserve)
            cairo_fill_preserve(*ctx);
        else
            cairo_fill(*ctx);
    }
//#####################################################################################################################
}
