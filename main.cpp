#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

//All of the classes. Let the compiler create it. The rule of zero
struct vec3
{
	vec3(float vecx,float vecy,float vecz) : x{vecx},y{vecy},z{vecz}
	{

	}
	//operator

	//We'll try to do OO raw, but we will most certainly have to search a lot of shit up mane.'
	vec3() = delete;
	float x;
	float y;
	float z;



	vec3 operator+ (vec3 v)
	{
		return vec3(x+v.x, y+v.y, z+v.z);
	}
	vec3 operator- (vec3 v)
	{
		return vec3(x-v.x, y-v.y, z-v.z);
	}
	//Scaler
	vec3 operator* (int scale)
	{
		return vec3(x*scale, y*scale, z*scale);
	}

	void normalize()
	{
		float len = (x*x) + (y*y) + (z*z);
		len = std::sqrt(len);

		x = (x)/len;
		y = (y)/len;
		z = (z)/len;
	}

};


struct color
{
	color(int r_number,int g_number,int b_number) : r(r_number),g(g_number),b(b_number)
	{
		//Look into design contracts
		assert(r >= 0 && r <= 255);
		assert(g >= 0 && g <= 255);
		assert(b >= 0 && b <= 255);
	}

	color() : r{255}, g{0}, b{0}
	{

	}

	int r;
	int g;
	int b;
};


struct pixel
{
	pixel(float loc_x, float loc_y,float loc_z) : loc(loc_x, loc_y,loc_z)
	{

	}

	vec3 loc;
	color c;
};
struct canvas
{
	canvas() = default;
	static const int canvas_width {50};
	static const int canvas_height {20};
	static const int total_index = canvas_width * canvas_height;

};


struct viewport{
	//We're going to have to map to a 2d board, and our image to render to the canvas is quite literally
	vec3 camera{0,0,0}; //this is the origin

	const float width = 1.0f;
	const float height = 1.0f;
	const float distance = 1.0f;

	//Viewport is the 2d shit, and I think canvas is for generating the

	//Why is this getting converted to an int? I have no idea :(

	void map_viewport_to_canvas(const canvas c)
	{
		const float scaler_x = width / c.canvas_width;
		const float scaler_y = height / c.canvas_height;
		for(float i = 0.0f; i < c.canvas_width; ++i)
		{
			for(float j = 0.0f; j < c.canvas_height; ++j)
			{
				viewport_final_draw.push_back({i* scaler_x,j * scaler_y,1});
			}
		}
	}


	std::vector<pixel> viewport_final_draw;

};

void ray_target_pixel(vec3 viewport_pixel)
	{
		//Normalize, so we take a normalized vector, then scale it using t, and rays can go on forever

		viewport_pixel.normalize();

		//t * D - which is a normalized vector for the point on the viewport.
		//this feels like it going to be a while loop, until something happens to the ray. I just don't know what tho.'
		//this isn't exactly what I want, I still don't even know a minimal piece of this that I can test yet :(

		//So this ray thing is pretty much entirely dependent on intersection so I'm just going to leave this here.'

		//So I'm trying to simulate a ray here. But it's not working out all that great.
		float t = .1f;
		while(t <= 5.0f) //I don't know what to use instead of this 5.0 thingy honestly.
		{
			viewport_pixel = viewport_pixel * t;
		}
	}

int main()
{
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

	v.map_viewport_to_canvas(c);


	//ray_target_pixel(v.viewport_final_draw[0].loc);

	//std::cout << v.viewport_final_draw[0].loc.x << " " << v.viewport_final_draw[0].loc.y << " " << v.viewport_final_draw[0].loc.z << "\n ";


}
/*
 * v.map_viewport_to_canvas(c);
	for(int i = 0; i < c.total_index; i++)
	{
		std::cout << v.viewport_final_draw[i].loc.x << " " << v.viewport_final_draw[i].loc.y << " " << v.viewport_final_draw[i].loc.z << "\n ";
	}
 *
 */



