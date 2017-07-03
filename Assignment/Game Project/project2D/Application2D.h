#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include"Font.h"
#include"Vector2.h"
#include"Player.h"

//gamestates
#include"GameStateManager.h"
#include"GameState.h"
#include"SplashScreen.h"
#include"MainMenu.h"
#include"PlayState.h"
#include"PauseMenu.h"
#include"Quit.h"

//resource manager
#include"Resource.h"
#include"ResourceManager.h"
#include"ResourceBase.h"

//factory
#include"Factory.h"
#include"Bubble.h"
#include<list>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	
	//gsm vars
	GameStateManager*	m_gsm;
	std::shared_ptr<ResourceBase>		m_menuMusic;
	std::shared_ptr<ResourceBase>		m_font;
	std::shared_ptr<ResourceBase>		m_menuTexture;
	std::shared_ptr<ResourceBase>		m_playerSpriteIdle;
	std::shared_ptr<ResourceBase>		m_playerSpriteW1;
	std::shared_ptr<ResourceBase>		m_playerSpriteW2;

	//factory vars
	std::unique_ptr<Factory>			m_factory;
	std::list<std::shared_ptr<Bubble>>	m_bubbles;

	//resource manager
	std::shared_ptr<ResourceBase>	m_images;
	std::shared_ptr<ResourceBase>	m_audio;
	Player*							m_player;

	float m_cameraX, m_cameraY;
	float m_timer;
};