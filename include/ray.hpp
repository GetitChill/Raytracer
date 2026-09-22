#include "vec3.hpp"


struct ray
{
     ray() : origin{0.0f,0.0f,0.0f}
     {
     }
	 raytracer::vec3 direction;
	 raytracer::vec3 origin;
 };
