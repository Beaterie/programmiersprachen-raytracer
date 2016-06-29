#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>
#include <cmath>
#include <string>
#include "color.hpp"
#include <iostream>
#include "ray.hpp"

class Sphere : public Shape{
public:
	Sphere();
	Sphere(glm::vec3 const& ctr, float r, Material const& material, std::string const& name);
	Sphere(Sphere const& s);
	~Sphere();

	glm::vec3 const& get_center() const;
	float get_radius() const;
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& ray, float& t) override;

private:
	glm::vec3 ctr_;
	float r_;

};


#endif