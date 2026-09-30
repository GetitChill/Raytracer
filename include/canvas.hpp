#include "vec3.hpp"
#include "pixel.hpp"
#include <vector>
#include <fstream>

#pragma once
struct canvas
{
	
	canvas(int w, int h) : width{w}, height{h}, canvasvec(w * h)
	{
	
	}
	canvas() : width{240}, height{300}
	{

	}
	
	int width;
	int height;
	
	std::vector<pixel> canvasvec;
	std::ofstream image;
};

void canvas_to_ppm(canvas * c);
void write_pixel(canvas* c, const int x,  const int y,const color color_p);
color pixel_at(canvas* c, const int x,  const int y);

raytracer::vec3 convert_pixels_to_viewport(const int canvas_x, const int canvas_y, int canvas_w, int canvas_h, raytracer::vec3 viewport_points);



