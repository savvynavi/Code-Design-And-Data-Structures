#include"MainMenu.h"
#include"GameStateManager.h"
#include"Application.h"

MainMenu::MainMenu(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, std::shared_ptr<ResourceBase> texture, std::shared_ptr<ResourceBase> audio, GameStateManager* gsm){
	m_renderer = renderer;
	m_font = font;
	m_audio = audio;
	m_texture = texture;
	m_gsm = gsm;
	m_menuSelect = 0;
	m_selectorHeight = 400;
	m_input = aie::Input::getInstance();
	m_buttonSound = ResourceManager::getInstance().get("./audio/click.wav", ResourceManager::AUDIO);

}

MainMenu::~MainMenu(){

}

void MainMenu::onUpdate(float deltaTime){
	m_audio->as<aie::Audio>()->play();
	if(m_input->wasKeyPressed(aie::INPUT_KEY_SPACE)){
		//change to switch with more menu options?

		if(m_menuSelect == 0){
			//transition to play state
			m_gsm->popState();
			m_gsm->pushState(PLAY_STATE);
			onEnter();
		}else if(m_menuSelect == 1){
			//quit
			m_gsm->popState();
			m_gsm->pushState(QUIT);
		}
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_DOWN) && m_menuSelect < 1){
		m_buttonSound->as<aie::Audio>()->play();
		m_selectorHeight -= 100;
		m_menuSelect++;
	}
	if(m_input->wasKeyPressed(aie::INPUT_KEY_UP) && m_menuSelect > 0){
		m_buttonSound->as<aie::Audio>()->play();
		m_selectorHeight += 100;
		m_menuSelect--;
	}
}

void MainMenu::onDraw(){
	m_renderer->drawSprite(m_texture->as<aie::Texture>(), 1280 / 2, 600);
	m_renderer->drawText(m_font->as<aie::Font>(), "PLAY", (1280 / 2) - 120, 400);
	m_renderer->drawText(m_font->as<aie::Font>(), "QUIT", (1280 / 2) - 120, 300);
	m_renderer->drawText(m_font->as<aie::Font>(), ">", (1280 / 2) - 150, m_selectorHeight);
}