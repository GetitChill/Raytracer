#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "vec3.hpp"

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


}

 TEST_CASE("SCALING VEC")
{
	vec3 a(1.0, -2.0,3.0);
	a = vec3_scale(a, 3.5f);
	REQUIRE_THAT( a.x, Catch::Matchers::WithinAbs(3.5f, .0005));
	REQUIRE_THAT( a.y, Catch::Matchers::WithinAbs(-7.0f, .0005));
	REQUIRE_THAT( a.z, Catch::Matchers::WithinAbs(10.5f, .0005));
}



TEST_CASE("Magnitude of vector")
{
	vec3 a(1.0, 2.0,3.0);
	float v = vec3_mag(a);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(std::sqrt(14), .0005));

	vec3 b (1.0,0.0,0.0);
	v = vec3_mag(b);
	REQUIRE_THAT( v, Catch::Matchers::WithinAbs(1.0f, .0005));

}


TEST_CASE("Normalized vector")
{
	vec3 a(4.0, 0.0, 0.0);
	vec3 norm_a = vec3_normalized(a);
	REQUIRE_THAT(norm_a.x ,Catch::Matchers::WithinAbs(1.0f, .0005) );
	REQUIRE_THAT(norm_a.y ,Catch::Matchers::WithinAbs(0.0f, .0005) );
	REQUIRE_THAT(norm_a.z ,Catch::Matchers::WithinAbs(0.0f, .0005) );
	

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
