#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"

class SplashScreen : public GameState{
public:
	SplashScreen(aie::Renderer2D* renderer, aie::Font* font);
	virtual ~SplashScreen();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
protected:
	aie::Renderer2D* m_renderer;
	aie::Font* m_font;
	float m_timer;
};