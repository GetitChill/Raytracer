#pragma once

namespace raytracer{
	struct vec3
	{
		vec3(float vecx,float vecy,float vecz);
		vec3() = delete;
		float x;
		float y;
		float z;
	};
}
