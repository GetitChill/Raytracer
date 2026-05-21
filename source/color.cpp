#include "color.hpp"
#include <cassert>

raytracer::color::color(int r_number,int g_number,int b_number) : r(r_number),g(g_number),b(b_number)
{
		//Look into design contracts
		assert(r >= 0 && r <= 255);
		assert(g >= 0 && g <= 255);
		assert(b >= 0 && b <= 255);
}

raytracer::color::color() : r{255}, g{0}, b{0}
{

}
