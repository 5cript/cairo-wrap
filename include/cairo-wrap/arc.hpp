#pragma once

#include "shape.hpp"

namespace Cairo
{
#   define CAIRO_WRAP_INTERNAL_CAST(X) static_cast <T> (X)
    namespace internal {
        template <typename T>
        constexpr T sqrt (T of, T x = CAIRO_WRAP_INTERNAL_CAST(1), int rbi = 15) {
            return (rbi == 1) ? x : sqrt(of, x - (x * x - of) / (2 * x), rbi - 1);
        }

        template <typename T>
        constexpr T sqrt_2_estimator(T previous, int rbi = 20) {
            return (rbi == 1) ? previous : sqrt_2_estimator((previous + (CAIRO_WRAP_INTERNAL_CAST(2) / previous))/CAIRO_WRAP_INTERNAL_CAST(2), rbi-1);
        }
        constexpr long double sqrt_2 = internal::sqrt_2_estimator <long double> (1.);

        template <typename T>
        constexpr T pi_estimator(T a = CAIRO_WRAP_INTERNAL_CAST(1), T b = CAIRO_WRAP_INTERNAL_CAST(1) / CAIRO_WRAP_INTERNAL_CAST(sqrt_2), T t = CAIRO_WRAP_INTERNAL_CAST(1)/CAIRO_WRAP_INTERNAL_CAST(4), T p = CAIRO_WRAP_INTERNAL_CAST(1), int rbi = 5) {
            return (rbi == 1) ? ((((a+b)/ CAIRO_WRAP_INTERNAL_CAST(2)) + sqrt(a*b)) * (((a+b)/ CAIRO_WRAP_INTERNAL_CAST(2)) + sqrt(a*b))) / (4 * (t - p * ( (a - (a + b) / CAIRO_WRAP_INTERNAL_CAST(2)) * (a - (a + b) / CAIRO_WRAP_INTERNAL_CAST(2)) )))
                : pi_estimator(/* a */ (a+b)/ CAIRO_WRAP_INTERNAL_CAST(2),
                               /* b */ sqrt(a*b),
                               /* t */ t - p * ( (a - (a + b) / CAIRO_WRAP_INTERNAL_CAST(2)) * (a - (a + b) / CAIRO_WRAP_INTERNAL_CAST(2)) ),
                               /* p */ CAIRO_WRAP_INTERNAL_CAST(2) * p,
                               rbi - 1)
            ;
        }

        constexpr long double pi = internal::pi_estimator <long double>();
    }

    class Arc : public Shape
    {
    public:
        Arc(DrawContext* ctx, double x = 0., double y = 0., double radius = 0., double startAngle = 0., double endAngle = 2. * internal::pi);
        void draw(Pen const& line, Pen const& fill) override;

        static double toRadian(double degree) noexcept;

    protected:
        double radius_;
        double startAngle_;
        double endAngle_;
    };
#   undef CAIRO_WRAP_INTERNAL_CAST
}
