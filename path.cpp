#include "path.hpp"

namespace Cairo
{
	Path::Path(DrawContext* ctx, double x, double y)
		: Shape(ctx, x, y)
	{
		
	}			
	void Path::start()
	{
		cairo_new_sub_path(*ctx_);
	}
	void Path::lineTo(double x, double y)
	{
		cairo_line_to(*ctx_, x, y);
	}
	void Path::finish()
	{
		cairo_close_path(*ctx_);
	}
	void Path::draw(Pen const& line, Pen const& fill)
	{
		Cairo::stroke(ctx_, line);
	}
}