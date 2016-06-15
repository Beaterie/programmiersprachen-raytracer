#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>
#include <cmath>
#include <string>
#include "color.hpp"

class Sphere : public Shape{
public:
	Sphere();
	Sphere(glm::vec3 const& ctr, float r, Color const& color_, std::string const& name_);
	Sphere(Sphere const& s);
	/*~Sphere();*/

	glm::vec3 const& get_center() const;
	float get_radius() const;
	float area() const override;
	float volume() const override;

private:
	glm::vec3 ctr;
	float r;

};
#endif