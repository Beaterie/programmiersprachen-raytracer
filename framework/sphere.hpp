#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>

class Sphere : public Shape{
public:
	Sphere();
	Sphere(glm::vec3 const ctr, float r);
	Sphere(Sphere const& s);

	glm::vec3 const& get_center() const;
	float get_radius() const;

private:
	glm::vec3 ctr;
	float r;
};

#endif