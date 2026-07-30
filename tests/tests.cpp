#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "vec3.hpp"
#include "canvas.hpp"
//I need to find a way to not be testing equality float.

using namespace raytracer;
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
	/*
	 * vec3 convert_pixels_to_viewport(const int canvas_x, const int canvas_y, int canvas_w, int canvas_h, vec3 viewport_points)
	{
		float c_x_converted = (canvas_x * (viewport_points.x/canvas_w)) -  viewport_points.x/2.0f;
		float c_y_converted = -1*(canvas_y * (viewport_points.y/canvas_h)) +  viewport_points.y/2.0f;

		return vec3(c_x_converted,c_y_converted,1);
	}
	 * */



}
