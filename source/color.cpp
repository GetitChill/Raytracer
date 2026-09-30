#include "color.hpp"



color color_add(const color lhs, const color rhs)
{
     return(color(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b) );
}

color color_subtraction(const color lhs, const color rhs)
{
    return(color(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b) );
}


color color_scaler(const color lhs, const float scale)
{
    return(color(lhs.r * scale, lhs.g * scale, lhs.b * scale) );
}
color color_multiplier(const color lhs, const color rhs)
{
	return(color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b) );
}



