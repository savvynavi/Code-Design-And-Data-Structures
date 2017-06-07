#include"MainMenu.h"
#include"GameStateManager.h"

MainMenu::MainMenu(aie::Renderer2D* renderer, aie::Font* font, aie::Texture* texture, GameStateManager* gsm){
	m_renderer = renderer;
	m_font = font;
	m_texture = texture;
	m_gsm = gsm;
	m_menuSelect = 0;
	m_selectorHeight = 400;
	m_input = aie::Input::getInstance();
}

MainMenu::~MainMenu(){

}

void MainMenu::onUpdate(float deltaTime){
	if(m_input->wasKeyPressed(aie::INPUT_KEY_SPACE)){
		if(m_menuSelect == 0){
			//transition to play state
			m_gsm->popState();
			m_gsm->pushState(PLAY_STATE);
		}else if(m_menuSelect == 1){
			//quit
		}
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_DOWN) && m_menuSelect < 1){
		m_selectorHeight -= 100;
		m_menuSelect++;
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_UP) && m_menuSelect > 0){
		m_selectorHeight += 100;
		m_menuSelect--;
	}
}

void MainMenu::onDraw(){
	m_renderer->drawSprite(m_texture, 1280/2, 600);
	m_renderer->drawText(m_font, "PLAY", (1280 / 2) - 120, 400);
	m_renderer->drawText(m_font, "QUIT", (1280 / 2) - 120, 300);
	m_renderer->drawText(m_font, ">", (1280 / 2) - 150, m_selectorHeight);
}