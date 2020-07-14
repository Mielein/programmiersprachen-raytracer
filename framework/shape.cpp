#include "shape.hpp"

Shape::Shape(std::string name, Color colour):
name_{name},
colour_{colour}{}

std::ostream& Shape::print( std::ostream& os) const{
    std::cout<<"name: "<<name_<<"\n"<<"colour: "<<colour_<<std::endl;
}
std::ostream& operator<<(std::ostream& os ,Shape const& s){
    return s.print(os);
}