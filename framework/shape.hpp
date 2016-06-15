#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <string>
#include "color.hpp"


class Shape{
public:
	Shape();
	Shape(Color const& color_, std::string const& name_);
	Shape(Shape const& s);
	/*~Shape();*/

	virtual float area() const = 0;
	virtual float volume() const = 0;
	float stay_positiv(float a) const;
	std::string get_name() const;
	Color const& get_color() const;

protected:
	Color color_;
	std::string name_;

private:

};
#endif