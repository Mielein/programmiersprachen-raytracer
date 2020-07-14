#include "box.hpp"
#include <cmath>

Box::Box(glm::vec3 min, glm::vec3 max,std::string name, Color colour):
    min_{min},
    max_{max},
    Shape (name, colour){}

float Box::area() const{
    return 2*((max_.x-min_.x)*(max_.y-min_.y)+(max_.y-min_.y)*(max_.z-min_.z)+(max_.x-min_.x)*(max_.z-min_.z));
}

float Box::volume() const{
    return (max_.x-min_.x)*(max_.y-min_.y)*(max_.z-min_.z);
}