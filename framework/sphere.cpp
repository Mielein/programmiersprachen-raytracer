#include "sphere.hpp"
#include <cmath>
Sphere::Sphere(glm::vec3 mid,float rad,std::string name,Color colour):
    mid_{mid},
    radius_{rad},
    Shape(name,colour){}

float Sphere::area() const{
    return 4*M_PI*pow(radius_,2);
}
float Sphere::volume() const{
    return 4/3*M_PI*pow(radius_,3);
}