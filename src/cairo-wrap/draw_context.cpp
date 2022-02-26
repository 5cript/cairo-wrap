#include <cairo-wrap/draw_context.hpp>

namespace Cairo
{
    DrawContext::DrawContext(Surface* surface)
        : surface_{surface}
        , ctx_{cairo_create(*surface)}
    {
    }
    DrawContext::~DrawContext()
    {
        cairo_destroy(ctx_);
    }
    void DrawContext::fill(color_space r, color_space g, color_space b, color_space a)
    {
        save();
        cairo_set_source_rgba(
            ctx_,
            static_cast <double> (r) / colorMax,
            static_cast <double> (g) / colorMax,
            static_cast <double> (b) / colorMax,
            static_cast <double> (a) / colorMax
        );
        cairo_set_operator(ctx_, CAIRO_OPERATOR_SOURCE);
        cairo_paint(ctx_);
        restore();
    }
    void DrawContext::fill(RGBA color)
    {
        fill(color.r, color.g, color.b, color.a);
    }
    void DrawContext::save()
    {
        cairo_save(ctx_);
    }
    void DrawContext::restore()
    {
        cairo_restore(ctx_);
    }
}
