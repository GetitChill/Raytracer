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
	return vec3(main_vec.x * -1.0f, main_vec.y * -1.0f,main_vec.z * -1.0f);
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

//I'm not really sure how to normalize a vector.
raytracer::vec3 raytracer::vec3_normalized(vec3 main_v)
{
	float length = vec3_mag(main_v);

	return vec3(main_v.x / length, main_v.y / length, main_v.z / length );
}

//
float raytracer::vec3_dotproduct(vec3 first, vec3 second)
{
	return (first.x * second.x + first.y * second.y + first.z * second.z);
}

raytracer::vec3 raytracer::vec3_crossproduct(vec3 first, vec3 second)
{
	return vec3(
			first.y * second.z - first.z * second.y,
			first.z * second.x - first.x * second.z, 
			first.x * second.y - first.y * second.x );
}
