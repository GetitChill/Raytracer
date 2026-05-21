#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

//All of the classes. Let the compiler create it. The rule of zero
//Constexpr
//namespace raytracer - put everything in my own namespace.
// Namespace rt::canvas - a namespace alias. Avoid collisions
//Mess with namespaces.


//Copy means we create an object

//Assignment means we change an existing one.

//Implicit convertions.
#include "vec3.hpp"
#include "color.hpp"
#include "pixel.hpp"
#include "canvas.hpp"
#include "viewport.hpp"

using namespace raytracer;
//Does this take away from having a namespace of my own I wonder :(

void ray_target_pixel(raytracer::vec3 viewport_pixel)
	{
		//Normalize, so we take a normalized vector, then scale it using t, and rays can go on forever
		//viewport_pixel.normalize();
		//GOING TO WANT TO NORMALIZE HERE.

		//t * D - which is a normalized vector for the point on the viewport.
		//this feels like it going to be a while loop, until something happens to the ray. I just don't know what tho.'
		//this isn't exactly what I want, I still don't even know a minimal piece of this that I can test yet :(

		//So this ray thing is pretty much entirely dependent on intersection so I'm just going to leave this here.'

		//So I'm trying to simulate a ray here. But it's not working out all that great.
		float t = .1f;
		while(t <= 5.0f) //I don't know what to use instead of this 5.0 thingy honestly.
		{
			//viewport_pixel = viewport_pixel * t;
		}
	}

int main()
{
	//Namespace alias.
	canvas c;
	viewport v;
	std::ofstream file;
	file.open("image.ppm");

	//there's got to be a better way to use the canvas values than just hardcoding them.
	file << "P3\n";
	file << 50 << " " << 20 << "\n";
	file << "255\n";
	file.close();

	//I want this thing to be done on each point of the veiwport so ...
	//This is just going to be for a single point on our viewport.
	//We're going to be changing this thing maybe?


	std::cout << "Hello World";
	v.map_viewport_to_canvas(c);
	//ray_target_pixel(v.viewport_final_draw[0].loc);

	//std::cout << v.viewport_final_draw[0].loc.x << " " << v.viewport_final_draw[0].loc.y << " " << v.viewport_final_draw[0].loc.z << "\n ";
}
/*
	v.map_viewport_to_canvas(c);
	for(int i = 0; i < c.total_index; i++)
	{
		std::cout << v.viewport_final_draw[i].loc.x << " " << v.viewport_final_draw[i].loc.y << " " << v.viewport_final_draw[i].loc.z << "\n ";
	}
 *
*/



