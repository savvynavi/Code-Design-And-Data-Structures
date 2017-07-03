#include"PauseMenu.h"
#include"GameStateManager.h"

PauseMenu::PauseMenu(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm){
	m_font = font;
	m_renderer = renderer;
	m_gsm = gsm;
	this->onEnter();
}

PauseMenu::~PauseMenu(){

}

void PauseMenu::onEnter(){
	m_selectorHeight = 400;
	m_menuSelect = 0;
	m_buttonSound = ResourceManager::getInstance().get("./audio/click.wav", ResourceManager::AUDIO);
	m_input = aie::Input::getInstance();
}

void PauseMenu::onUpdate(float deltaTime){
	if(m_input->wasKeyPressed(aie::INPUT_KEY_SPACE)){
		//change to switch with more menu options?
		if(m_menuSelect == 0){
			//transition to play state
			m_gsm->popState();
			m_gsm->pushState(PLAY_STATE);
		}else if(m_menuSelect == 1){
			//quit to menu
			m_gsm->popState();
			m_gsm->pushState(MAIN_MENU);
		}else if(m_menuSelect == 2){
			//quit to desktop
			m_gsm->popState();
			m_gsm->pushState(QUIT);
		}
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_DOWN) && m_menuSelect < 2){
		m_buttonSound->as<aie::Audio>()->play();
		m_selectorHeight -= 50;
		m_menuSelect++;
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_UP) && m_menuSelect > 0){
		m_buttonSound->as<aie::Audio>()->play();
		m_selectorHeight += 50;
		m_menuSelect--;
	}
}

void PauseMenu::onDraw(){
	m_renderer->setRenderColour(0.6f, 0, 0.25f);
	m_renderer->drawBox((1280 / 2), (720 / 2), 400, 150);
	m_renderer->setRenderColour(0, 0, 0);
	m_renderer->drawText(m_font->as<aie::Font>(), "Resume", (1280 / 2) - 120, 400);
	m_renderer->drawText(m_font->as<aie::Font>(), "Quit To Menu", (1280 / 2) - 120, 350);
	m_renderer->drawText(m_font->as<aie::Font>(), "Quit To Desktop", (1280 / 2) - 120, 300);
	m_renderer->drawText(m_font->as<aie::Font>(), ">", (1280 / 2) - 150, m_selectorHeight);
}