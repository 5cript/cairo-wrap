#pragma once

#include "shape.hpp"

namespace Cairo
{
	class Path : public Shape
	{
	public:
		Path(DrawContext* ctx, double x = 0., double y = 0.);
		
		void start();
		
		void lineTo(double x, double y);
		
		void finish();
		
		void draw(Pen const& line, Pen const& fill);
	};
	
}