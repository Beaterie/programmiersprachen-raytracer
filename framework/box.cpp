#include "box.hpp"

Box::Box():
	min{},
	max{}
	{}

Box::Box(glm::vec3 const min, glm::vec3 const max):
	min{min},
	max{max}
	{}

Box::Box(Box const& b):
	min{b.min},
	max{b.max}
	{}

glm::vec3 const& Box::get_min() const {
	return min;
}

glm::vec3 const& Box::get_max() const {
	return max;
}