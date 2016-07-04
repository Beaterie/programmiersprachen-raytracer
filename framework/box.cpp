#include "box.hpp"

Box::Box():
	Shape{{}, "New_Box"}, //ganz oben hin
	min_{0.0f,0.0f,0.0f},
	max_{0.0f,0.0f,0.0f}
	{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
	Shape{{}, "New_Box"},
	min_{min},
	max_{max}
	{
		min_.x = std::min(min.x,max.x);
		min_.y = std::min(min.y,max.y);
		min_.z = std::min(min.z,max.z);
		max_.x = std::max(min.x,max.x);
		max_.y = std::max(min.y,max.y);
		max_.z = std::max(min.z,max.z);
	}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Material const& material, std::string const& name):
	Shape{material, name},
	min_{min},
	max_{max}
	{
		min_.x = std::min(min.x,max.x);
		min_.y = std::min(min.y,max.y);
		min_.z = std::min(min.z,max.z);
		max_.x = std::max(min.x,max.x);
		max_.y = std::max(min.y,max.y);
		max_.z = std::max(min.z,max.z);
	}

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

bool Box::intersect(Ray const& ray, float& t) const{
	bool result = false;
	int z_1{0};
	int z_2{0};
	int z_3{0};
	float s_1{0};
	float s_2{0};
	float s_3{0};

	//Ebenen parallel zur y,z-Ebene
	if (ray.get_direction().x != 0){
		//für die Seiten beim Minimum
		glm::vec3 schnittpunkt_1{};
		float v_1 = (min_.x-ray.get_origin().x) / ray.get_direction().x;
		schnittpunkt_1.x = ray.get_origin().x + v_1*ray.get_direction().x;
		schnittpunkt_1.y = ray.get_origin().y + v_1*ray.get_direction().y;
		schnittpunkt_1.z = ray.get_origin().z + v_1*ray.get_direction().z;
		//für die Seiten beim Maximum
		glm::vec3 schnittpunkt_2{};
		float v_2 = (max_.x-ray.get_origin().x) / ray.get_direction().x;
		schnittpunkt_2.x = ray.get_origin().x + v_2*ray.get_direction().x;
		schnittpunkt_2.y = ray.get_origin().y + v_2*ray.get_direction().y;
		schnittpunkt_2.z = ray.get_origin().z + v_2*ray.get_direction().z;
		//Tests ob Schnittpunkte in der Box
		//beide in Box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_1 = std::min( distance_two_vecs(schnittpunkt_1,ray.get_origin()),
			distance_two_vecs(schnittpunkt_2,ray.get_origin()) );
			z_1 = 1;
		}
		//nur schnittpunkt_1 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == false)
		{
			s_1 = distance_two_vecs(schnittpunkt_1,ray.get_origin());
			z_1 = 1;
		}
		//nur schnittpunkt_2 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == false &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_1 = distance_two_vecs(schnittpunkt_2,ray.get_origin());
			z_1 = 1;
		}
		//std::cout << "Erstens: distance = " << s_1 << " und " << z_1 << std::endl;
	}
	//Ebenen parallel zur x,z-Ebene
	if (ray.get_direction().y != 0){
		//für die Seiten beim Minimum
		glm::vec3 schnittpunkt_1{};
		float v_1 = (min_.y-ray.get_origin().y) / ray.get_direction().y;
		schnittpunkt_1.x = ray.get_origin().x + v_1*ray.get_direction().x;
		schnittpunkt_1.y = ray.get_origin().y + v_1*ray.get_direction().y;
		schnittpunkt_1.z = ray.get_origin().z + v_1*ray.get_direction().z;
		//für die Seiten beim Maximum
		glm::vec3 schnittpunkt_2{};
		float v_2 = (max_.y-ray.get_origin().y) / ray.get_direction().y;
		schnittpunkt_2.x = ray.get_origin().x + v_2*ray.get_direction().x;
		schnittpunkt_2.y = ray.get_origin().y + v_2*ray.get_direction().y;
		schnittpunkt_2.z = ray.get_origin().z + v_2*ray.get_direction().z;
		//Tests ob Schnittpunkte in der Box
		//beide in Box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_2 = std::min( distance_two_vecs(schnittpunkt_1,ray.get_origin()),
			distance_two_vecs(schnittpunkt_2,ray.get_origin()) );
			z_2 = 1;
		}
		//nur schnittpunkt_1 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == false)
		{
			s_2 = distance_two_vecs(schnittpunkt_1,ray.get_origin());
			z_2 = 1;
		}
		//nur schnittpunkt_2 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == false &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_2 = distance_two_vecs(schnittpunkt_2,ray.get_origin());
			z_2 = 1;
		}
		//std::cout << "Zweitens: distance = " << s_2 << " und " << z_2 << std::endl;
	}
	//Ebenen parallel zur x,y-Ebene
	if (ray.get_direction().z != 0){
		//für die Seiten beim Minimum
		glm::vec3 schnittpunkt_1{};
		float v_1 = (min_.z-ray.get_origin().z) / ray.get_direction().z;
		schnittpunkt_1.x = ray.get_origin().x + v_1*ray.get_direction().x;
		schnittpunkt_1.y = ray.get_origin().y + v_1*ray.get_direction().y;
		schnittpunkt_1.z = ray.get_origin().z + v_1*ray.get_direction().z;
		//für die Seiten beim Maximum
		glm::vec3 schnittpunkt_2{};
		float v_2 = (max_.z-ray.get_origin().z) / ray.get_direction().z;
		schnittpunkt_2.x = ray.get_origin().x + v_2*ray.get_direction().x;
		schnittpunkt_2.y = ray.get_origin().y + v_2*ray.get_direction().y;
		schnittpunkt_2.z = ray.get_origin().z + v_2*ray.get_direction().z;
		//Tests ob Schnittpunkte in der Box
		//beide in Box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_3 = std::min( distance_two_vecs(schnittpunkt_1,ray.get_origin()),
			distance_two_vecs(schnittpunkt_2,ray.get_origin()) );
			z_3 = 1;
		}
		//nur schnittpunkt_1 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == true &&
			is_in_box(min_, max_, schnittpunkt_2) == false)
		{
			s_3 = distance_two_vecs(schnittpunkt_1,ray.get_origin());
			z_3 = 1;
		}
		//nur schnittpunkt_2 in box
		if (is_in_box(min_, max_, schnittpunkt_1) == false &&
			is_in_box(min_, max_, schnittpunkt_2) == true)
		{
			s_3 = distance_two_vecs(schnittpunkt_2,ray.get_origin());
			z_3 = 1;
		}
		//std::cout << "Drittens: distance = " << s_3 << " und " << z_3 << std::endl;
	}

	//drei Schnittpunkte
	if (z_1 == 1 && z_2 == 1 && z_3 == 1){
		//std::cout << "Davor1: " << t << std::endl;
		t = std::min(std::min(s_1,s_2),s_3);
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	//zwei Schnittpunkte
	if (z_1 == 1 && z_2 == 1 && z_3 == 0){
		//std::cout << "Davor2: " << t << std::endl;
		t = std::min(s_1,s_2);
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	if (z_1 == 1 && z_3 == 1 && z_2 == 0){
		//std::cout << "Davor3: " << t << std::endl;
		t = std::min(s_1,s_3);
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	if (z_2 == 1 && z_3 == 1 && z_1 == 0){
		//std::cout << "Davor4: " << t << std::endl;
		t = std::min(s_2,s_3);
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	//ein Schnittpunkt
	if (z_1 == 0 && z_2 == 0 && z_3 == 1){
		//std::cout << "Davor5: " << t << std::endl;
		t = s_3;
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	if (z_1 == 0 && z_3 == 0 && z_2 == 1){
		//std::cout << "Davor6: " << t << std::endl;
		t = s_2;
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	if (z_2 == 0 && z_3 == 0 && z_1 == 1){
		//std::cout << "Davor7: " << t << std::endl;
		t = s_1;
		//std::cout << "Danach: " << t << std::endl;
		result = true;
	}
	//kein Schnittpunkt
	if (z_1 == 0 && z_2 == 0 && z_3 == 0){
		result = false;
	}
	return result;
}

// member function: checks whether a given point is in a box or not
bool Box::in_box(glm::vec3 const& test) const{
	bool result = false;
	if (test.x >= min_.x && test.x <= max_.x){
    	if (test.y >= min_.y && test.y <= max_.y){
    		if (test.z >= min_.z && test.z <= max_.z){
    			result = true;
    		}
    	}
    }
   	return result;
}

// free function: checks whether a given point is in a box or not 
bool is_in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point) {
	Box b {min, max};
    return b.in_box(point);
}

float distance_two_vecs(glm::vec3 const& p1, glm::vec3 const& p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) +
		(p1.y-p2.y)*(p1.y-p2.y) +
		(p1.z-p2.z)*(p1.z-p2.z));
}



