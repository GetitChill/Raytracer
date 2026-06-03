#pragma once

#include "vec3.cpp"


namespace raytracer
{
	struct canvas
	{
		canvas() = default;

		//The canvas is going to be 3d so, we need have a z
		static const int canvas_width {50};
		static const int canvas_height {20};
		static const int canvas_z {20};



		static const int total_index = {canvas_width * canvas_height};

		//We could just send out a ray, and check if it's hitting our sphere using the p thereom.


		static const int sphere_radius = 5;
		vec3 sphere_center{canvas_width / 2, canvas_height / 2, canvas_z / 2};
	};
}
