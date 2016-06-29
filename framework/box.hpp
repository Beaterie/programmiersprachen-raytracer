#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <math.h>
#include <cmath>
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"
#include <iostream>
#include "ray.hpp"
#include <algorithm>

class Box : public Shape{
public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max, Material const& material, std::string const& name);
	Box(Box const& b);
	~Box();

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& ray, float& t) override;

private:
	glm::vec3 min_;
	glm::vec3 max_;

};

bool is_in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& test);
float distance_two_vecs(glm::vec3 const& p1, glm::vec3 const& p2);

#endif