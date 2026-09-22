#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>
#include "vec3.hpp"
#include "canvas.hpp"
#include <string>
#include <catch2/catch_session.hpp>
#include <cmath>
#include "sphere.hpp"
#include "ray.hpp"
#include "dimention.hpp"

using namespace raytracer;


int main()
{
	dimention width(240);
	dimention height(300);

	//Need to fix this viewport vec, cause that just doesn't make sense.
	const float viewport_distance = 1.0;
	const float viewport_width = 1.0;
	const float viewport_height = 1.0;


	vec3 viewport_dimentions(1.0f,1.0f,1.0f);
	vec3 camera(0.0f,0.0f,0.0f);

	sphere s;
	s.center = vec3(0.0f,0.0f,4.0f);
    s.radius = 1.0f;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n";
	file << width.length << " " << height.length << "\n";
	file << "255\n";

	std::string sample = "255 0 0 ";
	std::string black = "0 0 0 ";

	int hit = 0;
    //PPM expects rows first then columns
	for (int column = 0; column < height.length; column++)
	{
		for (int row = 0; row < width.length; row++)
		{
			vec3 h = convert_pixels_to_viewport(row,column,width.length,height.length, viewport_dimentions);
			ray r;
			//Subtraction -
			vec3 dif_between_camera_and_point = vec3_subtract(h, camera);
			vec3 dif_normalized = vec3_normalized(dif_between_camera_and_point);
			r.direction = dif_normalized;
			//Dot product
			//s.center, r.origin
			float t = vec3_dotproduct(vec3_subtract(s.center, r.origin), r.direction);
			//This is for the ray equation
			vec3 rdt = vec3_scale(r.direction, t);
			//vec3(r.direction.x * t,r.direction.y * t, r.direction.z * t );

			vec3 p = vec3_plus(r.origin, rdt);
			//vec3(r.origin.x + rdt.x,r.origin.y + rdt.y, r.origin.z + rdt.z);

			float y = vec3_mag(vec3_subtract(s.center, p));
				//vec3(s.center.x - p.x,s.center.y - p.y,s.center.z - p.z));

			if (t > 0 && y < s.radius)
			{
				++hit;
				file << sample;
			}
			else
			{
				file << black;
			}

		}
	}
	file.close();
	std::cout << hit;
}





