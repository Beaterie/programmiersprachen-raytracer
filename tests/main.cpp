#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"
#include "color.hpp"

TEST_CASE("Test of Sphere", "[Sphere]"){
	Sphere a{};
	Sphere b{{1.0f,2.0f,3.0f},4.0f,{0.1f,0.2f,0.3f},"Atmosphäre"};
	Sphere c{b};

	REQUIRE(a.get_center().x == Approx(0.0f));
	REQUIRE(a.get_center().y == Approx(0.0f));
	REQUIRE(a.get_center().z == Approx(0.0f));
	REQUIRE(a.get_radius() == Approx(0.0f));
	REQUIRE(a.area() == Approx(0.0f));
	REQUIRE(a.volume() == Approx(0.0f));
	REQUIRE(a.get_color().r == Approx(0.0f));
	REQUIRE(a.get_color().g == Approx(0.0f));
	REQUIRE(a.get_color().b == Approx(0.0f));
	REQUIRE(a.get_name() == "New_Sphere");

	REQUIRE(b.get_center().x == Approx(1.0f));
	REQUIRE(b.get_center().y == Approx(2.0f));
	REQUIRE(b.get_center().z == Approx(3.0f));
	REQUIRE(b.get_radius() == Approx(4.0f));
	REQUIRE(b.area() == Approx(64*M_PI));
	REQUIRE(b.volume() == Approx(64*M_PI*(4/3)));
	REQUIRE(b.get_color().r == Approx(0.1f));
	REQUIRE(b.get_color().g == Approx(0.2f));
	REQUIRE(b.get_color().b == Approx(0.3f));
	REQUIRE(b.get_name() == "Atmosphäre");

	REQUIRE(c.get_center().x == Approx(1.0f));
	REQUIRE(c.get_center().y == Approx(2.0f));
	REQUIRE(c.get_center().z == Approx(3.0f));
	REQUIRE(c.get_radius() == Approx(4.0f));
	REQUIRE(c.area() == Approx(64*M_PI));
	REQUIRE(c.volume() == Approx(64*M_PI*(4/3)));
	REQUIRE(c.get_color().r == Approx(0.1f));
	REQUIRE(c.get_color().g == Approx(0.2f));
	REQUIRE(c.get_color().b == Approx(0.3f));
	REQUIRE(c.get_name() == "Atmosphäre");
}

TEST_CASE("Test of Box", "[Box]"){
	Box a{};
	Box b{{0.0f,0.5f,1.0f},{2.0f,3.0f,4.0f},{0.4f,0.5f,0.6f},"Box of Lies"};
	Box c{b};

	REQUIRE(a.get_min().x == Approx(0.0f));
	REQUIRE(a.get_min().y == Approx(0.0f));
	REQUIRE(a.get_min().z == Approx(0.0f));
	REQUIRE(a.get_max().x == Approx(0.0f));
	REQUIRE(a.get_max().y == Approx(0.0f));
	REQUIRE(a.get_max().z == Approx(0.0f));
	REQUIRE(a.area() == Approx(0.0f));
	REQUIRE(a.volume() == Approx(0.0f));
	REQUIRE(a.get_color().r == Approx(0.0f));
	REQUIRE(a.get_color().g == Approx(0.0f));
	REQUIRE(a.get_color().b == Approx(0.0f));
	REQUIRE(a.get_name() == "New_Box");

	REQUIRE(b.get_min().x == Approx(0.0f));
	REQUIRE(b.get_min().y == Approx(0.5f));
	REQUIRE(b.get_min().z == Approx(1.0f));
	REQUIRE(b.get_max().x == Approx(2.0f));
	REQUIRE(b.get_max().y == Approx(3.0f));
	REQUIRE(b.get_max().z == Approx(4.0f));
	REQUIRE(b.area() == Approx(2.0f*2.5f*2.0f + 3.0f*2.5f*2.0f + 2.0f*3.0f*2.0f));
	REQUIRE(b.volume() == Approx(2.0f*2.5f*3.0f));
	REQUIRE(b.get_color().r == Approx(0.4f));
	REQUIRE(b.get_color().g == Approx(0.5f));
	REQUIRE(b.get_color().b == Approx(0.6f));
	REQUIRE(b.get_name() == "Box of Lies");

	REQUIRE(c.get_min().x == Approx(0.0f));
	REQUIRE(c.get_min().y == Approx(0.5f));
	REQUIRE(c.get_min().z == Approx(1.0f));
	REQUIRE(c.get_max().x == Approx(2.0f));
	REQUIRE(c.get_max().y == Approx(3.0f));
	REQUIRE(c.get_max().z == Approx(4.0f));
	REQUIRE(c.area() == Approx(2.0f*2.5f*2.0f + 3.0f*2.5f*2.0f + 2.0f*3.0f*2.0f));
	REQUIRE(c.volume() == Approx(2.0f*2.5f*3.0f));
	REQUIRE(c.get_color().r == Approx(0.4f));
	REQUIRE(c.get_color().g == Approx(0.5f));
	REQUIRE(c.get_color().b == Approx(0.6f));
	REQUIRE(c.get_name() == "Box of Lies");
}

TEST_CASE("Shape: print method", "[Aufgabe 5.5]") {
	Sphere s1{{0.4f, 2.3f, 1.2f}, 4.3f, {0.1f, 0.2f, 0.3f}, "Charlie Shapeling"};
	std::cout << s1 << std::endl;

	Sphere s2{{6.9f, 4.2f, -1.2f}, -6.9f, {0.9f, 0.35f, 0.2f}, "Kügelchen"};
	std::cout << s2 << std::endl;

	Box b1{};
	std::cout << b1 << std::endl;

	auto b_pointer = std::make_shared<Box>(Box{{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}, {1.0f, 0.3f, 0.5f}, "Ein Schach-tel vom Kuchen."});
	b_pointer -> print(std::cout);
	std::cout << std::endl;
}

TEST_CASE("intersectRaySphere", "[intersect]"){
	// Ray
	glm::vec3 ray_origin{0.0,0.0,0.0};
	// ray direction has to be normalized !
	// you can use:
	// v = glm::normalize(some_vector)
	glm::vec3 ray_direction{0.0,0.0,1.0};
	// Sphere
	glm::vec3 sphere_center{0.0,0.0,5.0};
	float sphere_radius {1.0};
	float distance {0.0};
	bool result = glm::intersectRaySphere(
	ray_origin, ray_direction, sphere_center,
	sphere_radius*sphere_radius, distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("Destructor: virtual vs. non-virtual", "[aufgabe5.8]") {
	Color red(255, 0, 0); 
	glm::vec3 position(0, 0, 0);

	Sphere* s1 = new Sphere(position, 1.2, red, "Sphere 1");
	Shape* s2 = new Sphere(position, 1.2, red, "Sphere 2");

	std::cout << std::endl;
	s1 -> print(std::cout); 
	std::cout << std::endl;
	s2 -> print(std::cout);
	std::cout << std::endl;

	delete s1; 
	delete s2;

	/*
	virtual: ruft erst den Unterklassen-Destruktor (Sphere),
	dann den Basisklasse (Shape) für beide Beispiele
    non-virtual:
    Sphere 1: ruft zuerst den Destruktor der Klasse Sphere,
    dann den der Klasse (Shape)
    Sphere 2: Ruft nur den Destruktor der Klasse Shape 
    => kommt zu Resource Leak, bei dem die erworbenen Ressourcen
    nicht mehr vom Programm freigegeben werden
    Ist der Destruktor nicht als virtual deklariert kommt es zu
    "undefinied behaviour", was zu bugs fuehren kann. 
    Virtual Destructors sind immer dann nuetzlich, wenn eine Klasse
    polymorph verwendet wird (bzw. mindestens eine 
    virtuelle Funktion vorhanden ist)
    http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    */
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
