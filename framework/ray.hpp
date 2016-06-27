#ifndef RAY_HPP
#define RAY_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{
	Ray():
		origin{},
		direction{}
		{}

	Ray(glm::vec3 const& o, glm::vec3 const& d):
		origin{o},
		direction{glm::normalize(d)}
		{}

	glm::vec3 const& get_origin() const{
		return origin;
	}

	glm::vec3 origin;
	glm::vec3 direction;
};

#endif