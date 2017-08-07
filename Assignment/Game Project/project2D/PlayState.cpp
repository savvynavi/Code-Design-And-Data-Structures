#include"PlayState.h"
#include"GameStateManager.h"

PlayState::PlayState(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm){
	m_renderer = renderer;
	m_font = font;
	m_input = aie::Input::getInstance();
	m_gsm = gsm;
	m_timer = 0;
	m_idleSprite = ResourceManager::getInstance().get("./textures/caseyStand.png", ResourceManager::TEXTURE);
	m_walk1Sprite = ResourceManager::getInstance().get("./textures/caseyWalk1.png", ResourceManager::TEXTURE);
	m_walk2Sprite = ResourceManager::getInstance().get("./textures/caseyWalk2.png", ResourceManager::TEXTURE);
	m_currentSprite = m_idleSprite;
	
	//stuff

	x = 1280 / 2;
	y = 720 / 3;
}
//ADD ON ENTER THAT TRIGGERS FROM MAIN MENU ENTER
PlayState::~PlayState(){

}

void PlayState::onUpdate(float deltaTime){
	//game stuff here + pause menu
	if(m_input->isKeyDown(aie::INPUT_KEY_ESCAPE)){
		m_gsm->popState();
		m_gsm->pushState(PAUSE_MENU);
	}

	//fix this mess later => Have seperate state for player movement? would need less of this bs that can go wrong whenever
	//also player class that has a hitbox to be made in this gs
	if(m_input->isKeyDown(aie::INPUT_KEY_RIGHT)){
		m_timer += 1;
		x += 10;
		if(m_timer % 10 == 0){
			m_currentSprite = m_walk1Sprite;
		}else{
			m_currentSprite = m_walk2Sprite;
		}
	}else if(m_input->isKeyDown(aie::INPUT_KEY_LEFT)){
		m_timer += 1;
		x -= 10;
		if(m_timer % 10 == 0){
			m_currentSprite = m_walk1Sprite;
		} else{
			m_currentSprite = m_walk2Sprite;
		}
	}
}

void PlayState::onDraw(){
	m_renderer->drawSprite(m_currentSprite->as<aie::Texture>(), x, y);
	m_renderer->drawText(m_font->as<aie::Font>(), "GAME STATE", 1280 / 2, 700);
}