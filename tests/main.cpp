#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("test_of_List", "[List]"){
	REQUIRE(1 == true);
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
