#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>


class Shape{
public:
	Shape();
	Shape(Color const& color, std::string const& name);
	Shape(Shape const& s);
	/*~Shape();*/

	virtual float area() const = 0;
	virtual float volume() const = 0;
	float stay_positiv(float a) const;
	std::string get_name() const;
	Color const& get_color() const;
	virtual std::ostream& print(std::ostream& os) const;

protected:
	Color color_;
	std::string name_;

private:

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif