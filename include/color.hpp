#include "vec3.hpp"
#pragma once
struct color
{
	
	//color float {c}
	color(float cfr, float cfg, float cfb ) : r{cfr}, g{cfg}, b{cfb}
	{
	}
	//default black 
	color() : r{0.0f}, g{0.0f}, b{0.0f}
	{
	}
	float r;
	float g;
	float b;

};
color color_add(const color lhs, const color rhs);
color color_subtraction(const color lhs, const color rhs);
color color_scaler(const color lhs, const float scale);
color color_multiplier(const color lhs, const color rhs);


