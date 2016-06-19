#include "box.hpp"

Box::Box():
	min_{0.0f,0.0f,0.0f},
	max_{0.0f,0.0f,0.0f},
	Shape{{0.0f,0.0f,0.0f}, "New_Box"}
	{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, std::string const& name):
	min_{min},
	max_{max},
	Shape{color, name}
	{}

Box::Box(Box const& b):
	min_{b.min_},
	max_{b.max_},
	Shape{b.color_, b.name_}
	{}

glm::vec3 const& Box::get_min() const {
	return min_;
}

glm::vec3 const& Box::get_max() const {
	return max_;
}

float Box::area() const{
	return(stay_positiv(min_.x - max_.x) *	//2x Seite a
	stay_positiv(min_.y - max_.y) * 2 +
	stay_positiv(min_.z - max_.z)	*			//2x Seite b
	stay_positiv(min_.y - max_.y) * 2 +
	stay_positiv(min_.z - max_.z) *			//2x Seite c
	stay_positiv(min_.x - max_.x) * 2);
}

float Box::volume() const{
	return (stay_positiv(min_.x - max_.x) *	//Länge *
	stay_positiv(min_.y - max_.y) *			//Höhe *
	stay_positiv(min_.z - max_.z));			//Breite
}

std::ostream& Box::print(std::ostream& os) const{
	Shape::print(os);
	os <<
	"Minimum: (" <<
	min_.x << ", " <<
	min_.y << ", " <<
	min_.z <<
	")\nMaximum: (" <<
	max_.x << ", " <<
	max_.y << ", " <<
	max_.z << ")" <<
	std::endl;
	return os;
}

