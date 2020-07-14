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
std::ostream& Sphere::print( std::ostream& os) const{
    Shape::print(os);
    std::cout<<"center: "<<mid_.x<<", "<<mid_.y<<", "<<mid_.z<<std::endl;
    std::cout<<"radius: "<<radius_<<"\n"<<std::endl;
    std::cout<<"volume: "<<(*this).area()<<std::endl;
    std::cout<<"surface area: "<<(*this).volume()<<std::endl;
}