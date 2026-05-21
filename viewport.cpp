#include "viewport.hpp"
void raytracer::viewport::map_viewport_to_canvas(const canvas c)
	{
		const float scaler_x = raytracer::viewport::width / c.canvas_width;
		const float scaler_y = raytracer::viewport::height / c.canvas_height;
		for(float i = 0.0f; i < c.canvas_width; ++i)
		{
			for(float j = 0.0f; j < c.canvas_height; ++j)
			{
				viewport_final_draw.push_back({i* scaler_x,j * scaler_y,1});
			}
		}
	}
