#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"
#include"Input.h"
#include"Texture.h"

class GameStateManager;

class PlayState : public GameState{
public:
	PlayState(aie::Renderer2D* renderer, aie::Font* font, aie::Texture* texture, GameStateManager* gsm);
	virtual ~PlayState();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
protected:
	aie::Renderer2D* m_renderer;
	aie::Font* m_font;
	aie::Input* m_input;
	aie::Texture* m_texture;
	GameStateManager* m_gsm;
};