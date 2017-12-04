#include "Application2D.h"
#define CATCH_CONFIG_RUNNER
#include"catch.hpp"

TEST_CASE("testing GSM", "[GameStateManager]"){
	GameStateManager* testGSM = new GameStateManager(2);
	//aie::Renderer2D* renderer = new aie::Renderer2D();

	//std::shared_ptr<ResourceBase> m_font = ResourceManager::getInstance().get("./font/consolas_italic.ttf", ResourceManager::FONT);
	//std::shared_ptr<ResourceBase> m_menuTexture = ResourceManager::getInstance().get("./textures/title.png", ResourceManager::TEXTURE);
	//std::shared_ptr<ResourceBase> m_menuMusic = ResourceManager::getInstance().get("./audio/happy.wav", ResourceManager::AUDIO);
	
	//MainMenu* testState = new MainMenu(renderer, m_font, m_menuTexture, m_menuMusic, testGSM);
	//MainMenu test(dRenderer, );

	//MainMenu test(2dRenderer);
}

//TEST_CASE("Testing resource manager", "[ResourceManager]"){
//	std::shared_ptr<ResourceBase> resourceTest;
//	SECTION("Testing instance count"){
//		resourceTest = ResourceManager::getInstance().get("./textures/title.png", ResourceManager::TEXTURE);
//		REQUIRE(resourceTest.ResourceType == 0);
//	}
//}

int main(int argc, char* argv[]){
	int result = Catch::Session().run(argc, argv);

	auto app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return (result < 0xff ? result : 0xff);
}