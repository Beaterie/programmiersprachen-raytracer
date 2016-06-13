#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <math.h>
#include <glm/vec3.hpp>

class Box : public Shape{
public:
	Box();
	Box(glm::vec3 const min, glm::vec3 const max);
	Box(Box const& b);

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;

private:
	glm::vec3 min;
	glm::vec3 max;
};

#endif