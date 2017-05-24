#include "text.hpp"

namespace Cairo
{
//#####################################################################################################################
    Text::Text(DrawContext* ctx, double x, double y, std::string const& text, Font const& font)
        : Shape{ctx, x, y}
        , text_{text}
        , font_{font}
    {

    }
//---------------------------------------------------------------------------------------------------------------------
    void Text::draw(Pen const& line, Pen const& fill)
    {
        cairo_select_font_face(*ctx_, font_.family.c_str(), font_.slant, font_.weight);
        cairo_set_font_size(*ctx_, font_.size);
        applyPen(ctx_, line);
        cairo_text_extents_t te;
        cairo_text_extents(*ctx_, text_.c_str(), &te);
        cairo_move_to(*ctx_, x_ - te.x_bearing, y_ - te.y_bearing);
        cairo_show_text(*ctx_, text_.c_str());
    }
//---------------------------------------------------------------------------------------------------------------------
    BoundingBox Text::calculateBounds(Pen const& line) const
    {
        BoundingBox box;

        ctx_->save();
        cairo_select_font_face(*ctx_, font_.family.c_str(), font_.slant, font_.weight);
        cairo_set_font_size(*ctx_, font_.size);
        applyPen(ctx_, line);
        cairo_text_extents_t te;
        cairo_text_extents(*ctx_, text_.c_str(), &te);
        ctx_->restore();

        box.x = x_ - te.x_bearing;
        box.y = y_ - te.y_bearing;
        box.x2 = x_ - te.x_bearing + te.width;
        box.y2 = y_ - te.y_bearing + te.height;

        return box;
    }
//---------------------------------------------------------------------------------------------------------------------
    double Text::getBaselineDisplacement(Pen const& line) const
    {
        ctx_->save();
        cairo_select_font_face(*ctx_, font_.family.c_str(), font_.slant, font_.weight);
        cairo_set_font_size(*ctx_, font_.size);
        applyPen(ctx_, line);
        cairo_text_extents_t te;
        cairo_font_extents_t fe;
        cairo_text_extents(*ctx_, text_.c_str(), &te);
        cairo_font_extents (*ctx_, &fe);
        ctx_->restore();

        return (y_ - te.y_bearing + te.height) - (y_ - te.y_bearing) + te.y_bearing;
    }
//---------------------------------------------------------------------------------------------------------------------
    void Text::setFont(Font const& font)
    {
        font_ = font;
    }
//---------------------------------------------------------------------------------------------------------------------
    Font& Text::getFont()
    {
        return font_;
    }
//#####################################################################################################################
}
