#pragma once
namespace raytracer
{
	struct canvas
	{
		canvas() = default;
		static const int canvas_width {50};
		static const int canvas_height {20};
		static const int total_index = {canvas_width * canvas_height};

	};
}
