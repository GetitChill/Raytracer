#pragma once

#include "vec3.hpp"


namespace raytracer
{
	struct canvas
	{
		canvas() = default;

		//The canvas is going to be 3d so, we need have a z
		static constexpr float canvas_width {50.0f};
		static constexpr float  canvas_height {20.0f};
		static constexpr float canvas_z {20.0f};


		static constexpr float total_index = {canvas_width * canvas_height};

		//We could just send out a ray, and check if it's hitting our sphere using the p thereom.


		static constexpr float sphere_radius = 5.0f;
		vec3 sphere_center{canvas_width / 2, canvas_height / 2, canvas_z / 2};
	};
}
