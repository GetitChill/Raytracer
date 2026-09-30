#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "vec3.hpp"
#include "canvas.hpp"
#include "color.hpp"

//Will I need to include ifstream here? to test our file stream?
#include <fstream>
#include <string>
using namespace raytracer;
using namespace std;

TEST_CASE("Vec3 - point") {
	vec3 v(4.0,-4.2,3.1);
	REQUIRE_THAT( v.x, Catch::Matchers::WithinAbs(4.0, .0005));
	REQUIRE_THAT( v.y, Catch::Matchers::WithinAbs(-4.2, .0005));
	REQUIRE_THAT( v.z, Catch::Matchers::WithinAbs(3.1, .0005));

}

TEST_CASE("Vec3 - Vector")
{
	vec3 v(4.0,-4.2,3.1);
	
	REQUIRE_THAT( v.x, Catch::Matchers::WithinAbs(4.0, .0005));
	REQUIRE_THAT( v.y, Catch::Matchers::WithinAbs(-4.2, .0005));
	REQUIRE_THAT( v.z, Catch::Matchers::WithinAbs(3.1, .0005));


}


TEST_CASE("ADDING TWO VECS")
{
	vec3 a(1.0,2.2,3.3);
	vec3 b(4.4,5.5,6.6);
	
	vec3 c = vec3_plus(a, b);
	


	REQUIRE_THAT( c.x, Catch::Matchers::WithinAbs(5.4, .0005));
	REQUIRE_THAT( c.y, Catch::Matchers::WithinAbs(7.7, .0005));
	REQUIRE_THAT( c.z, Catch::Matchers::WithinAbs(9.9, .0005));



}


//I'm not stressing about the difference between a tuple and a vector..
TEST_CASE("SUBTRACTING VECS")
{
	vec3 a(3.0f,2.0f,1.0f);
	vec3 b(5.0f,6.0f,7.0f);


	vec3 c = vec3_subtract(a,b);

	REQUIRE_THAT( c.x, Catch::Matchers::WithinAbs(-2.0f, .0005));
	REQUIRE_THAT( c.y, Catch::Matchers::WithinAbs(-4.0f, .0005));
    REQUIRE_THAT( c.z, Catch::Matchers::WithinAbs(-6.0f, .0005));

}
TEST_CASE("Negating VEC")
{
	vec3 a(1.0, -2.0,3.0);
	a = vec3_negate(a);
	REQUIRE_THAT( a.x, Catch::Matchers::WithinAbs(-1.0f, .0005));
	REQUIRE_THAT( a.y, Catch::Matchers::WithinAbs(2.0f, .0005));
	REQUIRE_THAT( a.z, Catch::Matchers::WithinAbs(-3.0f, .0005));

	;


}

 TEST_CASE("SCALING VEC")
{
	vec3 a(1.0, -2.0,3.0);
	a = vec3_scale(a, 3.5f);
	REQUIRE_THAT( a.x, Catch::Matchers::WithinAbs(3.5f, .0005));
	REQUIRE_THAT( a.y, Catch::Matchers::WithinAbs(-7.0f, .0005));
	REQUIRE_THAT( a.z, Catch::Matchers::WithinAbs(10.5f, .0005));

	vec3 b(1.0, -2.0,3.0);
	b = vec3_scale(b, .5f);
	REQUIRE_THAT( b.x, Catch::Matchers::WithinAbs(.5f, .0005));
	REQUIRE_THAT( b.y, Catch::Matchers::WithinAbs(-1.0f, .0005));
	REQUIRE_THAT( b.z, Catch::Matchers::WithinAbs(1.5f, .0005));
}



TEST_CASE("Magnitude of vector")
{
	vec3 a(1.0, 2.0,3.0);
	float v = vec3_mag(a);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(std::sqrt(14), .0005));

	vec3 b (1.0,0.0,0.0);
	v = vec3_mag(b);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(1.0f, .0005));

	vec3 c (0.0,1.0,0.0);
	v = vec3_mag(c);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(1.0f, .0005));

	vec3 d (0.0,0.0,1.0);
	v = vec3_mag(d);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(1.0f, .0005));

	vec3 e(-1.0, -2.0,-3.0);
	v = vec3_mag(e);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(std::sqrt(14), .0005));
}


TEST_CASE("Normalized vector")
{
	vec3 a(4.0, 0.0, 0.0);
	vec3 norm_a = vec3_normalized(a);
	REQUIRE_THAT(norm_a.x ,Catch::Matchers::WithinAbs(1.0f, .0005) );
	REQUIRE_THAT(norm_a.y ,Catch::Matchers::WithinAbs(0.0f, .0005) );
	REQUIRE_THAT(norm_a.z ,Catch::Matchers::WithinAbs(0.0f, .0005) );

	vec3 b(1.0, 2.0, 3.0);
	vec3 norm_b = vec3_normalized(b);
	REQUIRE_THAT(norm_b.x ,Catch::Matchers::WithinAbs(.26726f, .0005) );
	REQUIRE_THAT(norm_b.y ,Catch::Matchers::WithinAbs(0.53452f, .0005) );
	REQUIRE_THAT(norm_b.z ,Catch::Matchers::WithinAbs(0.80178f, .0005) );


	float test_mag = vec3_mag(norm_a);
	REQUIRE_THAT(test_mag ,Catch::Matchers::WithinAbs(1.0f, .0005) );
}


TEST_CASE("Dot product")
{
	vec3 a(1.0,2.0,3.0);
	vec3 b(2.0,3.0,4.0);

	float dp = vec3_dotproduct(a,b);
	REQUIRE_THAT(dp, Catch::Matchers::WithinAbs(20.0f, .0005) );
}


TEST_CASE("cross product")
{
	vec3 a(1.0,2.0,3.0);
	vec3 b(2.0,3.0,4.0);

	vec3 c = vec3_crossproduct(a,b);	
 	REQUIRE_THAT(c.x ,Catch::Matchers::WithinAbs(-1.0f, .0005) );
	REQUIRE_THAT(c.y ,Catch::Matchers::WithinAbs(2.0f, .0005) );
	REQUIRE_THAT(c.z ,Catch::Matchers::WithinAbs(-1.0f, .0005) );
}


//Let's now test the math for the ray tracer/the functions that I implemented.
TEST_CASE("pixel to viewport")
{
	//This should be 0,0
	int canvas_w = 400;
	int canvas_h = 400;
	int canvas_x = 200;
	int canvas_y = 200;

	vec3 vp(1.0,1.0,1.0);

	vec3 test_points = vec3(convert_pixels_to_viewport(canvas_x,canvas_y,canvas_w,canvas_h,vp));
 	REQUIRE_THAT(test_points.x ,Catch::Matchers::WithinAbs(0.0f, .0005) );
	REQUIRE_THAT(test_points.y ,Catch::Matchers::WithinAbs(0.0f, .0005) );
	REQUIRE_THAT(test_points.z ,Catch::Matchers::WithinAbs(1.0f, .0005) );


	//This thing should definitely be pooping out viewport data points. Nothing else.

	canvas_x = canvas_w;
	canvas_y = canvas_h;
	vec3 t= vec3(convert_pixels_to_viewport(canvas_x,canvas_y,canvas_w,canvas_h,vp));
 	REQUIRE_THAT(t.x ,Catch::Matchers::WithinAbs(.5f, .0005) );
	REQUIRE_THAT(t.y ,Catch::Matchers::WithinAbs(-.5f, .0005) );
	REQUIRE_THAT(t.z ,Catch::Matchers::WithinAbs(1.0f, .0005) );
}


TEST_CASE("simple color creation")
{
	color c(-.5f, .4f, 1.7f);
	REQUIRE_THAT(c.r ,Catch::Matchers::WithinAbs(-.5f, .0005));
	REQUIRE_THAT(c.g ,Catch::Matchers::WithinAbs(.4f, .0005));
	REQUIRE_THAT(c.b ,Catch::Matchers::WithinAbs(1.7f, .0005));

}



TEST_CASE("add colors")
{
	color a(.9f, .6f,.75f);
	color b(.7f, .1f, .25f);
	color c = color_add(a,b);

	REQUIRE_THAT(c.r ,Catch::Matchers::WithinAbs(1.6f, .0005));
	REQUIRE_THAT(c.g ,Catch::Matchers::WithinAbs(.7f, .0005));
	REQUIRE_THAT(c.b ,Catch::Matchers::WithinAbs(1.0f, .0005));
}


TEST_CASE("subtract colors")
{
     color a(.9f, .6f,.75f);
     color b(.7f, .1f, .25f);
     color c = color_subtraction(a,b);

     REQUIRE_THAT(c.r ,Catch::Matchers::WithinAbs(.2f, .0005));
     REQUIRE_THAT(c.g ,Catch::Matchers::WithinAbs(.5f, .0005));
     REQUIRE_THAT(c.b ,Catch::Matchers::WithinAbs(.5f, .0005));
}

TEST_CASE("scale colors")
{
     color a(.2f, .3f,.4f);
     const float scale = 2.0f; 
	 color c = color_scaler(a,scale);

     REQUIRE_THAT(c.r ,Catch::Matchers::WithinAbs(.4f, .0005));
     REQUIRE_THAT(c.g ,Catch::Matchers::WithinAbs(.6f, .0005));
     REQUIRE_THAT(c.b ,Catch::Matchers::WithinAbs(.8f, .0005));
}


//color color_multiplier(const color lhs, const color rhs);
TEST_CASE("Multiplying/blending colors")
{
	color a(1.0f, .2f,.4f);
	color b(.9f, 1.f, .1f);
	color c = color_multiplier(a,b);

	REQUIRE_THAT(c.r ,Catch::Matchers::WithinAbs(.9f, .0005));
	REQUIRE_THAT(c.g ,Catch::Matchers::WithinAbs(.2f, .0005));
	REQUIRE_THAT(c.b ,Catch::Matchers::WithinAbs(.04f, .0005));

}


TEST_CASE("canvas init")
{
	canvas c;
	REQUIRE(c.width == 240);
    REQUIRE(c.height == 300);
	
	canvas ca(10,20);
	REQUIRE(ca.width == 10);
	REQUIRE(ca.height == 20);
	REQUIRE(ca.canvasvec.size() == (10 * 20));

	//Now we want to loop through the vector and make sure that all of the colors are 0,0,0
	for(int i = 0; i < 10*20; ++i)
	{
		REQUIRE(ca.canvasvec[i].pc.r == 0);
		REQUIRE(ca.canvasvec[i].pc.g == 0);
		REQUIRE(ca.canvasvec[i].pc.b == 0);

	}

}


TEST_CASE("set and get color for pixel in canvas")
{
	canvas c(20,20);

	int x = 10;
	int y = 10;

	write_pixel(&c, x, y, color(1.0f,0.0f,0.0f));

	//I don't think that we're writing to the correct thing. I think we're writing to a copy.
	
	//This is gonna be a problem - checking equality with a float.
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.r ,Catch::Matchers::WithinAbs(1.f, .0005));
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.g ,Catch::Matchers::WithinAbs(0.f, .0005));
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.b ,Catch::Matchers::WithinAbs(0.f, .0005));

	color co = pixel_at(&c, x, y);
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.r ,Catch::Matchers::WithinAbs(co.r, .0005));
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.g ,Catch::Matchers::WithinAbs(co.g, .0005));
	REQUIRE_THAT(c.canvasvec[y * c.width + x].pc.b ,Catch::Matchers::WithinAbs(co.b, .0005));
}


TEST_CASE("file test")
{
	//the header test.
	canvas c(20,20);
	canvas_to_ppm(&c);
	//Let's check that it's open
	bool open = c.image.is_open();

	REQUIRE(open == 1);

	//We want to read the first 3 lines.
	bool reading = true;
	//If one line is different then we change reading to false or something like that. 
	//We're just testing the first three lines
	ifstream teststream("image.ppm");


	REQUIRE(teststream.is_open());

	string cur;

	getline(teststream, cur);

	REQUIRE(cur == "P3");
	REQUIRE(reading == true);

	ifstream test("");		
}

