#pragma once

namespace Cairo
{
    struct BoundingBox
    {
        double x;
        double y;
        double x2;
        double y2;

        double getWidth() const
        {
            return x2 - x;
        }
        double getHeight() const
        {
            return y2 - y;
        }
        void move(double x, double y)
        {
            this->x = x;
            this->y = y;
            x2 = x2 + x;
            y2 = y2 + y;
        }
        void additiveMove(double x, double y)
        {
            move(this->x + x, this->y + y);
        }
        void setWidth(double width)
        {
            x2 = x + width;
        }
        void setHeight(double height)
        {
            y2 = y + height;
        }
    };
}
