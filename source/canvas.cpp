#include "canvas.hpp"
using namespace raytracer;

vec3 convert_pixels_to_viewport(const int canvas_x, const int canvas_y, int canvas_w, int canvas_h, vec3 viewport_points)
{
   float c_x_converted = (canvas_x * (viewport_points.x/canvas_w)) -  viewport_points.x/2;
   float c_y_converted = -1*(canvas_y * (viewport_points.y/canvas_h)) +  viewport_points.y/2;

   return vec3(c_x_converted,c_y_converted,1);
}



