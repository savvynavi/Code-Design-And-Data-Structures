#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"
#include"Input.h"
#include"Resource.h"
#include"ResourceManager.h"
#include"ResourceBase.h"

class GameStateManager;

class SplashScreen: public GameState{
public:
	SplashScreen(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm);
	virtual ~SplashScreen();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	void onExit();
protected:
	aie::Renderer2D* m_renderer;
	aie::Input* m_input;
	std::shared_ptr<ResourceBase> m_font;
	float m_timer;
	GameStateManager* m_gsm;
};