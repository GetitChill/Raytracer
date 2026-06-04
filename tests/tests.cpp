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

	INFO("You failed in making the point/tuple.");
}

TEST_CASE("Vec3 - Vector")
{
	vec3 v(4.0,-4.2,3.1);
	
	REQUIRE_THAT( v.x, Catch::Matchers::WithinAbs(4.0, .0005));
	REQUIRE_THAT( v.y, Catch::Matchers::WithinAbs(-4.2, .0005));
	REQUIRE_THAT( v.z, Catch::Matchers::WithinAbs(3.1, .0005));



	INFO("You failed to make a vector");
}
