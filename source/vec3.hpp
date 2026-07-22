#pragma once
//Need an include for the math of this shit - like square root and shit.
#include <cmath>

namespace raytracer{

	struct vec3
	{
		//Istuple is true if it's a tuple, which is determined by vec_tuple (which can be 0 or 1) 
		vec3(float vecx,float vecy,float vecz) : x{vecx},y{vecy},z{vecz}
		{
		
		}
		//We'll just use default for now cause delete is causing problems'
		vec3() = default;


		//do stand alone
		//Look into the spaceship operator.

		float x;
		float y;
		float z;
	};
	//I'm passing in copies here, so keep that in mind. In the future think about making them references if need be.
	
	vec3 vec3_plus(vec3 lhs, vec3 rhs);
	vec3 vec3_subtract(vec3 lhs, vec3 rhs);
	vec3 vec3_scale(vec3 lhs, float scale);
	vec3 vec3_normalize(vec3 lhs, vec3 rhs);
	vec3 vec3_negate(vec3 main_vec); //finds the opposite vector
	float vec3_mag(vec3 main_v);
	vec3 vec3_normalized(vec3 main_v); 
 	float vec3_dotproduct(vec3 first, vec3 second);
	vec3 vec3_crossproduct(vec3 first, vec3 second); //perpendicular 
}
