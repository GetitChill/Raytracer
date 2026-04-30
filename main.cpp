#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>


//We're going to implement a ray first.
//the ray will be shot at each pixel
//Need to figure out how to map to viewport
//test
//TODO add asserts for the screen aswell
struct vec2
{
	vec2(int vec2x,int vec2y) : x{vec2x},y{vec2y}
	{

	}
	vec2() = default;


	void vec2_init(int vec2x,int vec2y)
	{
		x = vec2x;
		y = vec2y;
	}
	int x;
	int y;
};
struct vec3
{
	vec3(int vecx,int vecy,int vecz) : x{vecx},y{vecy},z{vecz}
	{

	}

	int x;
	int y;
	int z;
};


struct color
{
	color(int r_number,int g_number,int b_number) : r(r_number),g(g_number),b(b_number)
	{

	}
	color() = default;

	int r;
	int g;
	int b;
};


struct pixel
{

	pixel() = default;
	vec2 loc;
	color c;
	void pixel_init(int loc_x, int loc_y)
	{
		loc.vec2_init(loc_x,loc_y);

	}
};
struct canvas
{
	canvas(int canvas_area, color population_color, int canvas_width, int canvas_height) : canvas_final_draw(canvas_area)
	{
		//So we initialize all of our x and y values for the canvas

		//We want to traverse every x for every y
		int counter = 0;
		for(int i = 0; i < canvas_height; i++)
		{
			for(int j = 0; j < canvas_width; j++)
			{
				canvas_final_draw[counter].pixel_init(j,i);
				counter++;
			}
			//I want to be able to do something like putpixel(x,y,red), and it do that;
		}
	}
	std::vector<pixel> canvas_final_draw;

	//That we're initializing values at compile time, we don't need to do that. We need to be able to set these values using a putpixel function, then just run the vector and run everything, includeing the pixels that have and don't have values.
	void putpixel(int pixel_x, int pixel_y, color col, int canvas_width, int canvas_height)
	{
		int counter = 0;
		for(int i = 0; i < canvas_height; i++)
		{
			for(int j = 0; j < canvas_width; j++)
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
	vec3 camera{0,0,0}; //this is the origin

	const int width = 1;
	const int height = 1;
	const int distance = 1;

	//this the ray equation o + t(v-o)
	//then we test for intersection.
};

int main()
{
	color red(255,0,0);

	static const int width = 50;
	static const int height = 20;
	static const int total_index = width * height;

	canvas canvas_object(total_index, red, width, height);

	vec3 origin(10,10,10);
	std::cout << origin.x << " " <<origin.y << " " <<origin.z << "\n" ;

	std::ofstream file;
	file.open("image.ppm");


	for(int i = 0; i < 10; i++)
	{
		canvas_object.putpixel(10, i, red, width, height);
	}



	file << "P3\n";
	file << width << " " << height << "\n";
	file << "255\n";

	for(unsigned int i = 0; i < total_index; i++)
	{
		file << canvas_object.canvas_final_draw[i].c.r << " " << canvas_object.canvas_final_draw[i].c.g << " " << canvas_object.canvas_final_draw[i].c.b  << " ";
	}

	file.close();
	for(unsigned int i = 0; i < total_index; i++)
	{

		std::cout << canvas_object.canvas_final_draw[i].loc.x << " ";
		std::cout << canvas_object.canvas_final_draw[i].loc.y << "\n";

	}
}


