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


using namespace raytracer;

int main()
{
	canvas c;
	viewport v;

	const int width {100};
	const int height {100};

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





