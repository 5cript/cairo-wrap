#include "surface.hpp"

namespace Cairo
{
    Surface::Surface(int width, int height)
        : surface_{cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height)}
    {

    }
    Surface::~Surface()
    {
        cairo_surface_destroy(surface_);
    }
    void Surface::saveToFile(std::string const& fileName) const
    {
        cairo_surface_write_to_png(surface_, fileName.c_str());
    }
}
