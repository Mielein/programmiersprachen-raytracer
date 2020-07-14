#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>


class Sphere : public Shape{
public:
    Sphere(glm::vec3 mid,float rad,std::string name, Color colour);
    float area() const override;
    float volume() const override;

private:
    glm::vec3 mid_;
    float radius_;
};

#endif