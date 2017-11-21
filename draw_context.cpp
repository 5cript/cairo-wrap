#include "draw_context.hpp"

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
        cairo_set_source_rgba (ctx_, r, g, b, a);
        cairo_set_operator(ctx_, CAIRO_OPERATOR_SOURCE);
        cairo_paint(ctx_);
        restore();
    }
    void DrawContext::fill(RGBA color)
    {
        save();
        cairo_set_source_rgba (ctx_, color.r, color.g, color.b, color.a);
        cairo_set_operator(ctx_, CAIRO_OPERATOR_SOURCE);
        cairo_paint(ctx_);
        restore();
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
