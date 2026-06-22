#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>
#include "vec3.hpp"
#include "color.hpp"
#include "pixel.hpp"
#include "canvas.hpp"
#include "viewport.hpp"
#include <string>
#include <catch2/catch_session.hpp>
#include <cmath>



//I'm going to have to learn how to use the debugger, and tmux, cause this workflow is dogshit.

using namespace raytracer;


struct vec3_test
{
	vec3_test(float nx, float ny, float nz) : x{nx}, y{ny}, z{nz} 
	{}

	vec3_test() = default;

	float x,y,z;
};
struct ray_test
{
	ray_test() : origin{0.0f,0.0f,0.0f}
	{
	}
	vec3_test direction;
	vec3_test origin;

};
struct sphere
{

	sphere() = default;
	int radius;
	vec3_test center;
};

vec3 convert_pixels_to_viewport(vec3 canvas_cords, int canvas_w, int canvas_h, vec3 viewport_points)
{
	//Z is 1 in this case cause the viewport has a distance of 1 in the z;
	return vec3(canvas_cords.x * (viewport_points.x/canvas_w),canvas_cords.y * (viewport_points.y/canvas_h),1); 
}


bool test_code( vec3 canvas_pixel_collision ,sphere circ, vec3 viewport_dimentions, int width, int height)
{


	vec3 canvas_point_pixel(canvas_pixel_collision.x,canvas_pixel_collision.y,canvas_pixel_collision.z);



	//We map our canvas 2d coordinates to our viewport 3 ones, so that we can operate in the 3d
	vec3 result =convert_pixels_to_viewport(canvas_point_pixel, width, height, viewport_dimentions);
	
	//So we shoot out our ray from the origin. This is a 3D vector
	ray_test r;

	//So now here we want to get the vector difference between the result (our screen into the 3d world), and the base from where we're shooting this ray.
	vec3 viewport_origin_vector(result.x - r.origin.x, result.y - r.origin.y, result.z - r.origin.z);

	//We calculate the length
	float length = std::sqrt(std::pow(viewport_origin_vector.x,2) + std::pow(viewport_origin_vector.y,2) + std::pow(viewport_origin_vector.z,2) );

	//Now we get the normalized magnitude to apply to the ray so that it hits that point on the viewport.
	r.direction.x = viewport_origin_vector.x/length ;
	r.direction.y = viewport_origin_vector.y/length ;
	r.direction.z = viewport_origin_vector.z/length ;

	//Ray sphere intersection code. Using the quadratic form 
	//a=d^2
	float a = std::pow(r.direction.x,2) + std::pow(r.direction.y,2) + std::pow(r.direction.z,2);

	//b=2dv
	//v = o - c
	vec3 va(r.origin.x - circ.center.x, r.origin.y - circ.center.y,r.origin.z - circ.center.z);
	float b = 2* ((r.direction.x * va.x) + (r.direction.y * va.y) + (r.direction.z * va.z));

	//c= v^2 - r^2
	
	float cva = std::pow(va.x,2) +  std::pow(va.y,2) +  std::pow(va.z,2) -  std::pow(circ.radius,2);

	//Solve for the t's
	float t1 = -b + std::sqrt((std::pow(b,2)) - 4*a*cva)/2*a;
	float t2 = -b - std::sqrt((std::pow(b,2)) - 4*a*cva)/2*a;


	if (t1 >= 0 || t2 >= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int main()
{

	//We set the coordinates of the canvas here.
	const int width{100};
	const int height{100};



	//these are the viewport dimentions. w, h, d
	vec3 viewport_dimentions(1.0,1.0,1.0);

	sphere cir;
	cir.radius = 5;
	cir.center.x = 2;
	cir.center.y = 3;
	cir.center.z = 4;


	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n";
	file << 50 << " " << 20 << "\n";
	file << "255\n";

	std::string sample = "255 0 0 ";
	


	for(int i = 0; i < width; ++i)
	{
		for(int j = 0; j< height; ++j)
		{
			if(test_code(vec3(i,j,0),cir,viewport_dimentions, width, height))
			{
				file << sample;
			}
			else
			{
				file << "0 0 0";
			}
		}
	}

	file.close();
	std::cout << "Correctly Compiled using make" << std::endl;

}





