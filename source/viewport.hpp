#include "canvas.hpp"
#include "pixel.hpp"
#include "vec3.hpp"
#include <vector>

namespace raytracer{
	struct viewport{

		vec3 camera{0,0,0};

		const float width = 1.0f;
		const float height = 1.0f;
		const float distance = 1.0f;

		std::vector<pixel> viewport_final_draw;
};

}
