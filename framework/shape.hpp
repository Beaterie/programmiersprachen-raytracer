#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>
#include "material.hpp"
#include "ray.hpp"


class Shape{
public:
	Shape();
	Shape(Material const& material, std::string const& name);
	Shape(Shape const& s);
	virtual ~Shape();

	virtual float area() const = 0;
	virtual float volume() const = 0;
	std::string const& get_name() const;
	Material const& get_material() const;
	virtual std::ostream& print(std::ostream& os) const;
	virtual bool intersect(Ray const& ray, float& t) const = 0;

protected:
	Material material_;
	std::string name_;

private:

};

float stay_positiv(float a);
std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif