#include "box.hpp"

Box::Box():
	min{0.0f,0.0f,0.0f},
	max{0.0f,0.0f,0.0f},
	Shape{{0.0f,0.0f,0.0f}, "New_Box"}
	{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color_, std::string const& name_):
	min{min},
	max{max},
	Shape{color_, name_}
	{}

Box::Box(Box const& b):
	min{b.min},
	max{b.max},
	Shape{b.color_, b.name_}
	{}

glm::vec3 const& Box::get_min() const {
	return min;
}

glm::vec3 const& Box::get_max() const {
	return max;
}

float Box::area() const{
	return(stay_positiv(min.x - max.x) *	//2x Seite a
	stay_positiv(min.y - max.y) * 2 +
	stay_positiv(min.z - max.z)	*			//2x Seite b
	stay_positiv(min.y - max.y) * 2 +
	stay_positiv(min.z - max.z) *			//2x Seite c
	stay_positiv(min.x - max.x) * 2);
}

float Box::volume() const{
	return (stay_positiv(min.x - max.x) *	//Länge *
	stay_positiv(min.y - max.y) *			//Höhe *
	stay_positiv(min.z - max.z));			//Breite
}