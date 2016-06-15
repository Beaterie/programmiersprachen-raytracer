#include "sphere.hpp"

Sphere::Sphere():
	ctr{0.0f,0.0f,0.0f},
	r{0.0f},
	Shape{{0.0f,0.0f,0.0f}, "New_Sphere"}
	{}

Sphere::Sphere(glm::vec3 const& ctr, float r, Color const& color_, std::string const& name_):
	ctr{ctr},
	r{r},
	Shape{color_, name_}
	{}

Sphere::Sphere(Sphere const& s):
	ctr{s.ctr},
	r{s.r},
	Shape{s.color_, s.name_}
	{}

glm::vec3 const& Sphere::get_center() const {
	return ctr;
}

float Sphere::get_radius() const {
	return r;
}

float Sphere::area() const{
	return r*r*M_PI*4;
}

float Sphere::volume() const{
	return r*r*r*M_PI*(4/3);
}