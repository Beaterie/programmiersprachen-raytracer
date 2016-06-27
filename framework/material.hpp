#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include "color.hpp"
#include <string>

struct Material
{
	Material():
		name_{"New_Material"},
		ka_{0.0f,0.0f,0.0f},
		kd_{0.0f,0.0f,0.0f},
		ks_{0.0f,0.0f,0.0f},
		m_{0.0f}
		{}

	Material(std::string const& name, Color const& ka,
		Color const& kd, Color const& ks, float m):
		name_{name},
		ka_{ka},
		kd_{kd},
		ks_{ks},
		m_{m}
		{}

	std::ostream& print(std::ostream& os) const{
		os <<
		"Material: " <<
		name_ << 
		"\nAmbient-Reflection: " <<
		ka_ <<
		"Diffuse-Reflection: " <<
		kd_ <<
		"Specular-Reflection: " <<
		ks_ <<
		"Exponent (m): " <<
		m_;
		return os;
	}

	friend std::ostream& operator<<(std::ostream& os, Material const& material){
		return material.print(os);
	};

	std::string name_;
	Color ka_;
	Color kd_;
	Color ks_;
	float m_;
};

#endif