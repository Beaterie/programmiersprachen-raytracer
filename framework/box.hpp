#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

class Box : public Shape{
public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color_, std::string const& name_);
	Box(Box const& b);
	/*~Box();*/

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;
	float area() const override;
	float volume() const override;

private:
	glm::vec3 min;
	glm::vec3 max;

};
#endif