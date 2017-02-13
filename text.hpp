#pragma once

#include "shape.hpp"
#include "font.hpp"
#include "bounding_box.hpp"

namespace Cairo
{
    class Text : public Shape
    {
    public:
        Text(DrawContext* ctx, double x, double y, std::string const& text, Font const& font);
        void draw(Pen const& line, Pen const& fill = {}) override;
        BoundingBox calculateBounds() const;

    private:
        std::string text_;
        Font font_;
    };
}
