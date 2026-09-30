#include "canvas.hpp"
using namespace raytracer;

void canvas_to_ppm(canvas* c)
{
	(*c).image.open("test.txt");
	(*c).image << "P3\n";
	(*c).image << (*c).width << " " << (*c).height << "\n";
	(*c).image << "255\n";
}
color pixel_at(canvas* c, const int x,  const int y)
{
	int vector_array_calculation = y*(*c).width + x;


return color((*c).canvasvec[vector_array_calculation].pc.r, (*c).canvasvec[vector_array_calculation].pc.g, (*c).canvasvec[vector_array_calculation].pc.b);
}
void write_pixel(canvas* c, const int x,  const int y,const color color_p)
{

	//We need to check this out;
	int vector_array_calculation = y*(*c).width + x;
	
	(*c).canvasvec[vector_array_calculation].pc.r = color_p.r;
	(*c).canvasvec[vector_array_calculation].pc.g = color_p.g;
	(*c).canvasvec[vector_array_calculation].pc.b = color_p.b;


}


vec3 convert_pixels_to_viewport(const int canvas_x, const int canvas_y, int canvas_w, int canvas_h, vec3 viewport_points)
{
   float c_x_converted = (canvas_x * (viewport_points.x/canvas_w)) -  (viewport_points.x/2.0f);
   float c_y_converted = -1*(canvas_y * (viewport_points.y/canvas_h)) +  viewport_points.y/2.0f;


   return vec3(c_x_converted,c_y_converted,1);
}



