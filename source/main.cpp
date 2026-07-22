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


using namespace raytracer;

int main()
{

	const int width{240};
	const int height{300};

	const float viewport_distance = 1.0;
	const float viewport_width = 1.0;
	const float viewport_height = 1.0;


	vec3 viewport_dimentions(1.0,1.0,1.0);
	vec3 camera(0.0,0.0,0.0);


	sphere s;
	s.center = vec3(0.0f,0.0f,4.0f);
    s.radius = 1.0;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n";
	file << width << " " << height << "\n";
	file << "255\n";

	std::string sample = "255 0 0 ";
	std::string black = "0 0 0 ";

	int hit = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			vec3 h = convert_pixels_to_viewport(j,i,width,height, viewport_dimentions);
			ray r;
			vec3 dif_between_camera_and_point = vec3(h.x - camera.x,h.y - camera.y,h.z - camera.z);
			vec3 dif_normalized = vec3_normalized(dif_between_camera_and_point);
			r.direction = dif_normalized;
			float t = vec3_dotproduct(vec3(s.center.x - r.origin.x,s.center.y - r.origin.y,s.center.z - r.origin.z), r.direction);
			vec3 rdt = vec3(r.direction.x * t,r.direction.y * t, r.direction.z * t );
			vec3 p = vec3(r.origin.x + rdt.x,r.origin.y + rdt.y, r.origin.z + rdt.z );

			float y = vec3_mag(vec3(s.center.x - p.x,s.center.y - p.y,s.center.z - p.z));

			if (y < s.radius)
			{
				++hit;
				file << sample;
				//float x = sqrt(s.radius * s.radius - y*y );
				//float t1 = t - x;
				//float t2 = t + x;
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





