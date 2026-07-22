cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(raytracer)
find_package (Catch2 3 REQUIRED)
add_executable(raytracer source/vec3.cpp source/canvas.cpp source/ray.cpp source/sphere.cpp source/main.cpp
)
target_include_directories(raytracer PRIVATE include)
#c++ standard is going to be 20



add_executable(test_prac source/vec3.cpp source/canvas.cpp source/ray.cpp source/sphere.cpp tests/tests.cpp)
target_link_libraries(test_prac PRIVATE Catch2::Catch2WithMain)
target_include_directories(test_prac PRIVATE include)


