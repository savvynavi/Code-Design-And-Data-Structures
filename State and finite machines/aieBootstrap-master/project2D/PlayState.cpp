#include"PlayState.h"
#include"GameStateManager.h"

PlayState::PlayState(aie::Renderer2D* renderer, aie::Font* font, aie::Texture* texture, GameStateManager* gsm){
	m_renderer = renderer;
	m_font = font;
	m_texture = texture;
	m_input = aie::Input::getInstance();
	m_gsm = gsm;
}

PlayState::~PlayState(){

}

void PlayState::onUpdate(float deltaTime){
	//game stuff here + pause menu
	if(m_input->isKeyDown(aie::INPUT_KEY_ESCAPE)){
		m_gsm->popState();
		m_gsm->pushState(MAIN_MENU);
	}
}

void PlayState::onDraw(){
	m_renderer->drawSprite(m_texture, 1280 / 2, 720 / 2);
	m_renderer->drawText(m_font, "GAME STATE", 1280 / 2, 700);
}