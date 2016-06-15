#include "shape.hpp"

Shape::Shape():
	color_{0.0f,0.0f,0.0f},
	name_{"New_Shape"}
	{}

Shape::Shape(Color const& color_, std::string const& name_):
	color_{color_},
	name_{name_}
	{}

Shape::Shape(Shape const& s):
	color_{s.color_},
	name_{s.name_}
	{}

float Shape::stay_positiv(float a) const{
	if (a < 0){
		return a*(-1.0f);
	}
	else{
		return a;
	}
}

std::string Shape::get_name() const{
	return name_;
}

Color const& Shape::get_color() const{
	return color_;
}