#pragma once

namespace raytracer{
	struct vec3
	{
		inline vec3(float vecx,float vecy,float vecz) : x{vecx},y{vecy},z{vecz}
		{
		
		}
		vec3() = delete;
		float x;
		float y;
		float z;
	};
}
