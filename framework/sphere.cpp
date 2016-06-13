#include "sphere.hpp"

Sphere::Sphere():
	ctr{0.0f, 0.0f, 0.0f},
	r{0.0f}
	{}

Sphere::Sphere(glm::vec3 const ctr, float r):
	ctr{ctr},
	r{r}
	{}

Sphere::Sphere(Sphere const& s):
	ctr{s.ctr},
	r{s.r}
	{}

glm::vec3 const& Sphere::get_center() const {
	return ctr;
}

float Sphere::get_radius() const {
	return r;
}