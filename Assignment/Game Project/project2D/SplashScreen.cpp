#include"SplashScreen.h"
#include"GameStateManager.h"

SplashScreen::SplashScreen(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm){
	m_font = font;
	m_renderer = renderer;
	m_timer = 0;
	m_gsm = gsm;
	m_input = aie::Input::getInstance();
}

SplashScreen::~SplashScreen(){

}

void SplashScreen::onExit(){

}

void SplashScreen::onUpdate(float deltaTime){
	m_timer += deltaTime;
	if((m_timer >= 3) || (m_input->wasKeyPressed(aie::INPUT_KEY_SPACE))){
		m_gsm->popState();
		m_gsm->pushState(MAIN_MENU);
	}
}

void SplashScreen::onDraw(){
	m_renderer->drawText(m_font->as<aie::Font>(), "SPLASH SCREEN", (1280 / 2) - 40, 500);
	m_renderer->drawText(m_font->as<aie::Font>(), "DEMO FOR TRANSITIONS AND STATE MANAGEMENT", (1280 / 2) - 160, 450);
}