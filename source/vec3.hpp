#pragma once

namespace raytracer{
	struct vec3
	{
		//Istuple is true if it's a tuple, which is determined by vec_tuple (which can be 0 or 1) 
		inline vec3(float vecx,float vecy,float vecz) : x{vecx},y{vecy},z{vecz}
		{
		
		}
		vec3() = delete; 

		vec3 operator+(vec3 v);

		float x;
		float y;
		float z;
	};
}
