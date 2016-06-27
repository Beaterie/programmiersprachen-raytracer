#include "box.hpp"

Box::Box():
	Shape{{}, "New_Box"}, //ganz oben hin
	min_{0.0f,0.0f,0.0f},
	max_{0.0f,0.0f,0.0f}
	{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Material const& material, std::string const& name):
	Shape{material, name},
	min_{min},
	max_{max}
	{}

Box::Box(Box const& b):
	Shape{b.material_, b.name_},
	min_{b.min_},
	max_{b.max_}
	{}

Box::~Box() {
    std::cout << "Box Destructor: " << name_ << std::endl;
}

glm::vec3 const& Box::get_min() const {
	return min_;
}

glm::vec3 const& Box::get_max() const {
	return max_;
}

float Box::area() const{
	return(stay_positiv(min_.x - max_.x) *	//2x Seite a
	stay_positiv(min_.y - max_.y) * 2 +
	stay_positiv(min_.z - max_.z)	*			//2x Seite b
	stay_positiv(min_.y - max_.y) * 2 +
	stay_positiv(min_.z - max_.z) *			//2x Seite c
	stay_positiv(min_.x - max_.x) * 2);
}

float Box::volume() const{
	return (stay_positiv(min_.x - max_.x) *	//Länge *
	stay_positiv(min_.y - max_.y) *			//Höhe *
	stay_positiv(min_.z - max_.z));			//Breite
}

std::ostream& Box::print(std::ostream& os) const{
	Shape::print(os);
	os <<
	"Minimum: (" <<
	min_.x << ", " <<
	min_.y << ", " <<
	min_.z <<
	")\nMaximum: (" <<
	max_.x << ", " <<
	max_.y << ", " <<
	max_.z << ")" <<
	std::endl;
	return os;
}

bool Box::intersect(Ray const& ry, float distance) const{
	// Probe ob Punkt im Quader liegt
    if ((ry.get_origin().x <= min_.x &&
    	ry.get_origin().x >= max_.x) ||
    	(ry.get_origin().x >= min_.x &&
    	ry.get_origin().x <= max_.x))
    {
    	if ((ry.get_origin().y <= min_.y &&
    		ry.get_origin().y >= max_.y) ||
    		(ry.get_origin().y >= min_.y &&
    		ry.get_origin().y <= max_.y))
    	{
    		if ((ry.get_origin().z <= min_.z &&
    			ry.get_origin().z >= max_.z) ||
    			(ry.get_origin().z >= min_.z &&
    			ry.get_origin().z <= max_.z))
    		{
    			return true;
    		}
    		else{
    			return false;
    		}
    	}
    	else{
    		return false;
    	}
    }
    else{
    	return false;
    }
}


