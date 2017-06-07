#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"

class GameStateManager;

class SplashScreen : public GameState{
public:
	SplashScreen(aie::Renderer2D* renderer, aie::Font* font, GameStateManager* gsm);
	virtual ~SplashScreen();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	void onExit();
protected:
	aie::Renderer2D* m_renderer;
	aie::Font* m_font;
	float m_timer;
	GameStateManager* m_gsm;
};