#include "Application2D.h"
#define CATCH_CONFIG_RUNNER
#include"catch.hpp"

//TEST_CASE("testing GSM", "[GameStateManager]"){
//	GameStateManager testGSM(3);
//	;
//	aie::Renderer2D* dRenderer = new aie::Renderer2D;
//	//MainMenu test(dRenderer, );
//
//	//MainMenu test(2dRenderer);
//}
//
//TEST_CASE("Testing resource manager", "[ResourceManager]"){
//
//}

int main(int argc, char* argv[]){
	int result = Catch::Session().run(argc, argv);

	auto app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return (result < 0xff ? result : 0xff);
}