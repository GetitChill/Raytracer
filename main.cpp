#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

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
	vec3 operator* (vec3 v)
	{
		return vec3(x*v.x, y*v.y, z*v.z);
	}
	//normalize
	void normalize() //how can I represent normalization
	{
	//why is this wrong?

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


struct pixel //Wait so wouldn't all of my pixels be a distance of 1 away from the camera (literally all of them?)'
{
	pixel(int loc_x, int loc_y,int loc_z) : loc(loc_x, loc_y,loc_z)
	{

	}
	vec3 loc;
	color c;

};
struct canvas
{
	canvas(int canvas_area, color population_color, int canvas_width, int canvas_height)
	{
		for(int i = 0; i < canvas_height; ++i)
		{
			for(int j = 0; j < canvas_width; ++j)
			{
				canvas_final_draw.push_back({i,j,1});
			}
		}
	}
	std::vector<pixel> canvas_final_draw;

	void putpixel(int pixel_x, int pixel_y, color col, int canvas_width, int canvas_height)
	{
		int counter = 0;
		for(int i = 0; i < canvas_height; ++i)
		{
			for(int j = 0; j < canvas_width; ++j)
			{
				if (canvas_final_draw[counter].loc.x == pixel_x && canvas_final_draw[counter].loc.y == pixel_y )
				{
					canvas_final_draw[counter].c = col;
					break;
				}
				counter++;
			}
		}
	}
};

struct viewport{
	//We're going to have to map to a 2d board, and our image to render to the canvas is quite literally
	vec3 camera{0,0,0}; //this is the origin

	const float width = 1.0f;
	const float height = 1.0f;
	const float distance = 1.0f;



	//Viewport is the 2d shit, and I think canvas is for generating the
	//So the viewport is 3d aswell, just has a constant z of 1; so we'll do something about that.'

	//How am I going to get direction I wonder IDK.


	void map_viewport_to_canvas(const canvas c)
	{
		int x{1000};
		//This is where we're going to map our canvas coordinates to our viewport, so I'm just going to loop through canvas and push_back the transformed values.
	}


	std::vector<pixel> viewport_final_draw;

	//this the ray equation o + t(v-o)
};

int main()
{
	color red(255,0,0);


	//So this shit should be going in my canvas object, but whatever.
	static const int canvas_width = 50;
	static const int canvas_height = 20;
	static const int total_index = canvas_width * canvas_height;

	canvas canvas_object(total_index, red, canvas_width, canvas_height);

	vec3 origin(10,10,10);
	std::cout << origin.x << " " <<origin.y << " " <<origin.z << "\n" ;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n";
	file << canvas_width << " " << canvas_height << "\n";
	file << "255\n";

	for(unsigned int i = 0; i < total_index; ++i)
	{
		file << canvas_object.canvas_final_draw[i].c.r << " " << canvas_object.canvas_final_draw[i].c.g << " " << canvas_object.canvas_final_draw[i].c.b  << " ";
	}

	file.close();
	for(unsigned int i = 0; i < total_index; ++i)
	{

		std::cout << canvas_object.canvas_final_draw[i].loc.x << " ";
		std::cout << canvas_object.canvas_final_draw[i].loc.y << "\n";

	}


	vec3 a(3,1,2);
	a.normalize();
	std::cout << a.x << " " << a.y << " " << a.z;

	std::cout << "\n " <<std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}


