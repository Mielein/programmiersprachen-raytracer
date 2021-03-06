#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"
#include <iostream>

class Shape{
    public:
    Shape();
    Shape(std::string name, Color color);
    virtual ~Shape();
    virtual float area() const = 0;
    virtual float volume() const = 0;
    virtual std::ostream& print( std::ostream& os) const;

    protected:
    std::string name_;
    Color colour_;
};

std::ostream& operator<<(std::ostream& os ,Shape const& s);

#endif