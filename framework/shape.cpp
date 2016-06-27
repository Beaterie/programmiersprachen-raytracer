#include "shape.hpp"

Shape::Shape():
	material_{},
	name_{"New_Shape"}
	{}

Shape::Shape(Material const& material, std::string const& name):
	material_{material},
	name_{name}
	{}

Shape::Shape(Shape const& s):
	material_{s.material_},
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
	"\n" <<
	material_ <<
	std::endl;
	return os;
}

std::string const& Shape::get_name() const{
	return name_;
}

Material const& Shape::get_material() const{
	return material_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
	return s.print(os);
};


