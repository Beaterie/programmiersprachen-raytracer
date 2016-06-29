#include "sphere.hpp"

Sphere::Sphere():
	Shape{{}, "New_Sphere"},
	ctr_{0.0f,0.0f,0.0f},
	r_{0.0f}
	{}

Sphere::Sphere(glm::vec3 const& ctr, float r, Material const& material, std::string const& name):
	Shape{material, name},
	ctr_{ctr},
	r_{r}
	{}

Sphere::Sphere(Sphere const& s):
	Shape{s.material_, s.name_},
	ctr_{s.ctr_},
	r_{s.r_}
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
	r_ <<
	std::endl;
	return os;
}

bool Sphere::intersect(Ray const& ray, float& t) const{
    return glm::intersectRaySphere(ray.origin, ray.direction, ctr_, r_ * r_, t);
}

