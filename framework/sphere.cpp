#include "sphere.hpp"

Sphere::Sphere():
	ctr_{0.0f,0.0f,0.0f},
	r_{0.0f},
	Shape{{0.0f,0.0f,0.0f}, "New_Sphere"}
	{}

Sphere::Sphere(glm::vec3 const& ctr, float r, Color const& color, std::string const& name):
	ctr_{ctr},
	r_{r},
	Shape{color, name}
	{}

Sphere::Sphere(Sphere const& s):
	ctr_{s.ctr_},
	r_{s.r_},
	Shape{s.color_, s.name_}
	{}

Sphere::~Sphere() {
    std::cout << "Sphere Destructor: " << name_ << std::endl;
}

glm::vec3 const& Sphere::get_center() const {
	return ctr_;
}

float Sphere::get_radius() const {
	return stay_positiv(r_);
}

float Sphere::area() const{
	return stay_positiv(r_)*stay_positiv(r_)*M_PI*4;
}

float Sphere::volume() const{
	return stay_positiv(r_)*stay_positiv(r_)*stay_positiv(r_)*M_PI*(4/3);
}

std::ostream& Sphere::print(std::ostream& os) const{
	Shape::print(os);
	os <<
	"Center: (" <<
	ctr_.x << ", " <<
	ctr_.y << ", " <<
	ctr_.z <<
	")\nRadius: " <<
	r_ << std::endl;
	return os;
}

bool Sphere::intersect(Ray const& ry, float distance) const {
    return glm::intersectRaySphere(ry.origin, ry.direction, ctr_, r_ * r_, distance);
}

