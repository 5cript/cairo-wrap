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
        cairo_set_source_rgba(*ctx, pen.color.r, pen.color.g, pen.color.b, pen.color.a);
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
