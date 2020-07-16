#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("testing_sphere_area","[sphere_area]"){
  Sphere test1({1.0f,1.0f,1.0f},1.0f);
  Sphere test2({-2.0f,-1.7f,1.0f},-2.0f);
  Sphere test3({1.0f,1.0f,1.0f},0.0f,"rhysphere",{0.0f,1.0f,0.0f});
  Sphere test4({1.0f,1.0f,1.0f},5.0f,"sakura",{0.0f,1.0f,0.0f});

  REQUIRE(test1.area() == Approx(12.566f).epsilon(0.1));
  REQUIRE(test2.area() == Approx(50.26f).epsilon(0.1));
  REQUIRE(test3.area() == Approx(0.0f).epsilon(0.1));
  REQUIRE(test4.area() == Approx(314.159f).epsilon(0.1));

}
TEST_CASE("testing_sphere_volume","[sphere_volume]"){
  Sphere test1({1.0f,1.0f,1.0f},1.0f);
  Sphere test2({-2.0f,-1.7f,1.0f},-2.0f);
  Sphere test3({1.0f,1.0f,1.0f},0.0f,"rhysphere",{0.0f,1.0f,0.0f});
  Sphere test4({1.0f,1.0f,1.0f},5.0f,"sakura",{0.0f,1.0f,0.0f});

  REQUIRE(test1.volume() == Approx(4.188).epsilon(0.1));
  REQUIRE(test2.volume() == Approx(33.510f).epsilon(0.1));
  REQUIRE(test3.volume() == Approx(0.0f).epsilon(0.1));
  REQUIRE(test4.volume() == Approx(523.598f).epsilon(0.1));
}
TEST_CASE("testing_box_area","[box_area]"){
  Box test1({1.0f,1.0f,1.0f},{2.0f,2.0f,2.0f});
  Box test2({-1.0f,-1.0f,-1.0f},{2.0f,2.0f,2.0f});
  Box test3({0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f},"???",{0.0f,1.0f,0.0f});
  Box test4({1.0f,4.0f,2.0f},{6.0f,28.0f,-1.0f});

  REQUIRE(test1.area() == Approx(6.0f).epsilon(0.1));
  REQUIRE(test2.area() == Approx(54.0f).epsilon(0.1));
  REQUIRE(test3.area() == Approx(0.0f).epsilon(0.1));
  REQUIRE(test4.area() == Approx(414.0f).epsilon(0.1));
}
TEST_CASE("testing_box_volume","[box_volume]"){
  Box test1({1.0f,1.0f,1.0f},{2.0f,2.0f,2.0f});
  Box test2({-1.0f,-1.0f,-1.0f},{2.0f,2.0f,2.0f});
  Box test3({0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f},"???",{0.0f,1.0f,0.0f});
  Box test4({1.0f,4.0f,2.0f},{6.0f,28.0f,-1.0f});

  REQUIRE(test1.volume() == Approx(1.0f).epsilon(0.1));
  REQUIRE(test2.volume() == Approx(27.0f).epsilon(0.1));
  REQUIRE(test3.volume() == Approx(0.0f).epsilon(0.1));
  REQUIRE(test4.volume() == Approx(360.0f).epsilon(0.1));
}
TEST_CASE("print_sphere","[sphere_print]"){
  Sphere test1({1.0f,1.0f,1.0f},1.0f);
  Sphere test2({-2.0f,-1.7f,1.0f},-2.0f);
  Sphere test3({1.0f,1.0f,1.0f},0.0f,"rhysphere",{0.0f,1.0f,0.0f});
  Sphere test4({1.0f,1.0f,1.0f},5.0f,"sakura",{0.0f,1.0f,0.0f});

  std::cout<<test1;
  std::cout<<test3;
}
TEST_CASE("print_box","[box_print]"){
  Box test1({1.0f,1.0f,1.0f},{2.0f,2.0f,2.0f});
  Box test2({-1.0f,-1.0f,-1.0f},{2.0f,2.0f,2.0f});
  Box test3({0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f},"???",{0.0f,1.0f,0.0f});
  Box test4({1.0f,4.0f,2.0f},{6.0f,28.0f,-1.0f});

  std::cout<<test1;
  std::cout<<test3;
}
TEST_CASE("intersect_ray_sphere","[intersect]"){
// Ray
glm::vec3 ray_origin{0.0f,0.0f,0.0f};
// ray direction has to be normalized!
// you can use :
//v = glm :: normalize ( some_vector )
glm::vec3 ray_direction {0.0f,0.0f,1.0f};

// Sphere
glm::vec3 sphere_center{0.0f,0.0f,5.0f};
float sphere_radius{1.0f};
float distance = 0.0f;
auto result = glm::intersectRaySphere (
ray_origin,ray_direction,
sphere_center,
sphere_radius * sphere_radius , // squared radius !!!
distance);
REQUIRE(distance == Approx(4.0f));

Sphere sphere{sphere_center,sphere_radius,"stinky",{0.0f,0.0f,1.0}};
Ray ray{ray_origin,ray_direction};
HitPoint hitpoint = sphere.intersect(ray);
REQUIRE(hitpoint.intersection);
REQUIRE(hitpoint.distance == Approx(4.0f));
REQUIRE(hitpoint.intersect_direction == ray_direction);
REQUIRE(hitpoint.intersect_pt == ray_origin+(distance*ray_direction));
}

TEST_CASE("another_intersect_test_case","[intersect]"){
  Sphere sphere{{1.0f,1.0f,1.0f},1.0f,"stinky",{0.0f,0.0f,1.0}};
  glm::vec3 ray_origin{0.0f,0.0f,0.0f};
  glm::vec3 ray_direction {0.0f,0.0f,0.0f};
  Ray ray{ray_origin,ray_direction};
  HitPoint hit = sphere.intersect(ray);
  REQUIRE(false == hit.intersection);
}

TEST_CASE("and_another_intersect_test_case","[intersect]"){
  Sphere sphere{{1.0f,1.0f,1.0f},1.0f,"stinky",{0.0f,0.0f,1.0}};
  glm::vec3 ray_origin{0.0f,0.0f,0.0f};
  glm::vec3 ray_direction {1.0f,0.5f,1.0f};
  Ray ray{ray_origin,ray_direction};
  HitPoint hit = sphere.intersect(ray);
  REQUIRE(hit.intersection);
}

void aufgabe8(){
  Color red{255,0,0};
  glm::vec3 position {0.0f,0.0f,0.0f};

  std::cout<<"creating s1"<<std::endl;
  Sphere* s1 = new Sphere{position,1.2f,"sphere0",red};
  std::cout<<"creating s2"<<std::endl;
  Shape* s2 = new Sphere{position,1.2f,"sphere1",red};
  s1->print(std::cout);
  s2-> print (std::cout);
  delete s1 ;
  delete s2 ;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
  aufgabe8();
}
//aufgabe 5.8                                   
//with virtual                                //without virtual
/* a wild sphere destructor has appeared      a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
name:                                         name: 
colour: (1,0,0)                               colour: (1,0,0)
center: 1, 1, 1                               center: 1, 1, 1
radius: 1                                     radius: 1
volume: 12.5664                               volume: 12.5664
surface area: 4.18879                         surface area: 4.18879
name: rhysphere                               name: rhysphere
colour: (0,1,0)                               colour: (0,1,0)
center: 1, 1, 1                               center: 1, 1, 1
radius: 0                                     radius: 0
volume: 0                                     volume: 0
surface area: 0                               surface area: 0
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
name:                                         name:  
colour: (1,0,0)                               colour: (1,0,0)
minimum: 1, 1, 1                              minimum: 1, 1, 1
maximum: 2, 2, 2                              maximum: 2, 2, 2
volume: 6                                     volume: 6 
surface area: 1                               surface area: 1 
name: ???                                     name: ???
colour: (0,1,0)                               colour: (0,1,0) 
minimum: 0, 0, 0                              minimum: 0, 0, 0 
maximum: 0, 0, 0                              maximum: 0, 0, 0 
volume: 0                                     volume: 0 
surface area: 0                               surface area: 0   
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!
a wild sphere destructor has appeared         a wild sphere destructor has appeared
Shape destructor is here to destruct!!        Shape destructor is here to destruct!!*/

//aufgabe 5.8
//with virtual
