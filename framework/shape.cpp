#include "shape.hpp"

Shape::Shape():
	color_{0.0f,0.0f,0.0f},
	name_{"New_Shape"}
	{}

Shape::Shape(Color const& color, std::string const& name):
	color_{color},
	name_{name}
	{}

Shape::Shape(Shape const& s):
	color_{s.color_},
	name_{s.name_}
	{}

Shape::~Shape() {
    std::cout << "Shape Destructor: " << name_ << std::endl;
}

float Shape::stay_positiv(float a) const{
	if (a < 0){
		return a*(-1.0f);
	}
	else{
		return a;
	}
}

std::ostream& Shape::print(std::ostream& os) const{
	os <<
	"Name: " <<
	name_ << 
	"\nColor: (" <<
	color_.r << ", " <<
	color_.g << ", " <<
	color_.b << ")" <<
	std::endl;
	return os;
}

std::string Shape::get_name() const{
	return name_;
}

Color const& Shape::get_color() const{
	return color_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
	return s.print(os);
};


