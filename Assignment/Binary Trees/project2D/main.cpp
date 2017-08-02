#include "Application2D.h"
#define CATCH_CONFIG_RUNNER
#include"catch.hpp"

//run unit tests here

TEST_CASE("Binary tree add/remove functions", "[BinaryTree]"){
	BinaryTree test;
	REQUIRE(test.isEmpty() == true);
	test.insert(10);
	test.insert(15);
	test.insert(5);
	REQUIRE(test.isEmpty() == false);
	SECTION("testing removal of root"){
		test.remove(10);
		REQUIRE(test.findRoot()->getData() == 15);
	}
	SECTION("removing leaves"){
		test.remove(5);
		REQUIRE(test.find(5) == nullptr);
	}
}

int main(int argc, char* argv[]) {
	int result = Catch::Session().run(argc, argv);
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;
	return (result < 0xff ? result : 0xff);
}