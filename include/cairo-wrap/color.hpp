#pragma once

#include <cstdint>
#include <limits>

namespace Cairo
{
    using color_space = uint8_t;
    constexpr auto colorMax = std::numeric_limits <color_space>::max();
    constexpr auto colorMin = std::numeric_limits <color_space>::min();

    struct RGB
    {
        color_space r;
        color_space g;
        color_space b;
    };

    struct RGBA : public RGB
    {
        color_space a;

        RGBA& operator=(RGBA const&) = default;
        RGBA& operator=(RGBA&&) = default;

        RGBA() = default;
        constexpr RGBA(RGB const& color)
            : RGB{color}
            , a{255}
        {

        }
        constexpr RGBA(RGBA const& color) = default;
        constexpr RGBA(RGBA&& color) = default;
        constexpr RGBA(color_space r, color_space g, color_space b, color_space a)
            : RGB{r, g, b}
            , a{a}
        {

        }
        RGBA& operator=(RGB const& color) noexcept
        {
            r = color.r;
            g = color.g;
            b = color.b;
            a = colorMax;
            return *this;
        }
    };

    namespace Colors
    {
        constexpr auto Red =        RGB{colorMax, colorMin, colorMin};
        constexpr auto Green =      RGB{colorMin, colorMax, colorMin};
        constexpr auto Blue =       RGB{colorMin, colorMin, colorMax};
        constexpr auto Yellow =     RGB{colorMax, colorMax, colorMin};
        constexpr auto Cyan =       RGB{colorMin, colorMax, colorMax};
        constexpr auto Magenta =    RGB{colorMax, colorMin, colorMax};
        constexpr auto White =      RGB{colorMax, colorMax, colorMax};
        constexpr auto Black =      RGB{colorMin, colorMin, colorMin};
        constexpr auto Gray =       RGB{colorMax/2, colorMax/2, colorMax/2};
    }
}
