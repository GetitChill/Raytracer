#pragma once
#include "vec3.hpp"
#include "color.hpp"

namespace raytracer{
	struct pixel
	{
		pixel(float loc_x, float loc_y,float loc_z);

		vec3 loc;
		color c;
};
}

