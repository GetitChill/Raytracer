#include "vec3.hpp"

 
/*
 *vec3 vec3_plus(vec3 lhs, vec3 rhs);
 vec3 vec3_subtract(vec3 lhs, vec3 rhs);
 vec3 vec3_scale(vec3 lhs, vec3 rhs);
 vec3 vec3_normalize(vec3 lhs, vec3 rhs);
*/




raytracer::vec3 raytracer::vec3_plus(vec3 lhs, vec3 rhs)
{
	return vec3(lhs.x + rhs.x,lhs.y + rhs.y,lhs.z + rhs.z);
}

//It does matter which goes where in the parameter.
raytracer::vec3 raytracer::vec3_subtract(vec3 lhs, vec3 rhs)
{
	return vec3(lhs.x - rhs.x,lhs.y - rhs.y,lhs.z - rhs.z);
}


//I may want to actually parameter in the future. I'm not sure.
raytracer::vec3 raytracer::vec3_negate(vec3 main_vec)
{
	return vec3(main_vec.x * -1, main_vec.y * -1,main_vec.z * -1);

}

raytracer::vec3 raytracer::vec3_scale(vec3 lhs, float scale)
{
	return vec3(lhs.x * scale,lhs.y * scale,lhs.z * scale);
}
float raytracer::vec3_mag(vec3 main_v)
{
	float d = (main_v.x * main_v.x)  + (main_v.y * main_v.y) + (main_v.z * main_v.z);
	float m = std::sqrt(d);
	return (m);
	
}

