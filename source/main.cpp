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

vec3_test convert_pixels_to_viewport(vec3_test canvas_cords, int canvas_w, int canvas_h, vec3_test viewport_points)
{
	//Z is 1 in this case cause the viewport has a distance of 1 in the z;
	return vec3_test(canvas_cords.x * (viewport_points.x/canvas_w),canvas_cords.y * (viewport_points.y/canvas_h),1); 
}
int main()
{

	//We set the coordinates of the canvas here.
	const int width{100};
	const int height{100};

	//We want to test wheather the p that passes through this point collides with our sphere, but should this be in viewport 
	vec3_test canvas_point_pixel(3,4,0); 

	//these are the viewport dimentions. w, h, d
	vec3_test viewport_dimentions(1.0,1.0,1.0);

	//We map our canvas 2d coordinates to our viewport 3 ones, so that we can operate in the 3d
	vec3_test result =convert_pixels_to_viewport(canvas_point_pixel, width, height, viewport_dimentions);
	
	//So we shoot out our ray from the origin. This is a 3D vector
	ray_test r;

	//So now here we want to get the vector difference between the result (our screen into the 3d world), and the base from where we're shooting this ray.
	vec3_test viewport_origin_vector(result.x - r.origin.x, result.y - r.origin.y, result.z - r.origin.z);

	//We calculate the length
	float length = std::sqrt(std::pow(viewport_origin_vector.x,2) + std::pow(viewport_origin_vector.y,2) + std::pow(viewport_origin_vector.z,2) );

	//Now we get the normalized magnitude to apply to the ray so that it hits that point on the viewport.
	r.direction.x = viewport_origin_vector.x/length ;
	r.direction.y = viewport_origin_vector.y/length ;
	r.direction.z = viewport_origin_vector.z/length ;

	std::cout << "This is the d " <<  r.direction.x  << " " << r.direction.y  << " " << r.direction.z << "\n\n\n\n";

	sphere cir;
	cir.radius = 5;
	cir.center.x = 2;
	cir.center.y = 3;
	cir.center.z = 4;



	//Ray sphere intersection code. Using the quadratic form 
	//a=d^2
	float a = std::pow(r.direction.x,2) + std::pow(r.direction.y,2) + std::pow(r.direction.z,2);

	//b=2dv
	//v = o - c
	vec3_test va(r.origin.x - cir.center.x, r.origin.y - cir.center.y,r.origin.z - cir.center.z);
	float b = 2* ((r.direction.x * va.x) + (r.direction.y * va.y) + (r.direction.z * va.z));
	std::cout << "This is the v " <<  viewport_origin_vector.x  << " " << viewport_origin_vector.y  << " " << viewport_origin_vector.z << "\n\n\n\n";

	//c= v^2 - r^2
	
	float cva = std::pow(va.x,2) +  std::pow(va.y,2) +  std::pow(va.z,2) -  std::pow(cir.radius,2);

	//Solve for the t's
	float t1 = -b + std::sqrt((std::pow(b,2)) - 4*a*cva)/2*a;
	float t2 = -b - std::sqrt((std::pow(b,2)) - 4*a*cva)/2*a;

	if (t1 >= 0 || t2 >= 0 )
	{
		std::cout << "\nWe made it biotch";
	}
	
	////Solve for solution of T;
	std::cout << a << " " << b << " " << cva<< "\n\n\n\n";

	canvas c;
	viewport v;


	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n";
	file << 50 << " " << 20 << "\n";
	file << "255\n";

	std::string sample = "255 0 0 ";
	//for every x we're going draw down for all the y's
	for(int i = 0; i < width; ++i)
	{
		for(int j = 0; j< height; ++j)
		{
			file << sample;
		}
	}


	file.close();
	std::cout << "Correctly Compiled using make" << std::endl;

}





