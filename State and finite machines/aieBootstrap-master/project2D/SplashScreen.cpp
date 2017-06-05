#include"SplashScreen.h"


SplashScreen::SplashScreen(aie::Renderer2D* renderer, aie::Font* font){
	m_font = font;
	m_renderer = renderer;
	m_timer = 0;
}

SplashScreen::~SplashScreen(){

}

void SplashScreen::onUpdate(float deltaTime){
	m_timer =+ deltaTime;
}

void SplashScreen::onDraw(){
	m_renderer->drawText(m_font, "testing test studio presents", (1280 / 2) - 120, 500);
	m_renderer->drawText(m_font, "HORSING AROUND", (1280 / 2) - 70, 450);
	m_renderer->drawText(m_font, "A FAKE KATAMARI RIPOFF THAT DOESN'T EXIST", (1280 / 2) - 160, 400);
}