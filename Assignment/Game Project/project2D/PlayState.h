#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"
#include"Input.h"
#include"Texture.h"
#include"Resource.h"
#include"ResourceManager.h"
#include"ResourceBase.h"

class GameStateManager;

class PlayState: public GameState{
public:
	PlayState(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm);
	virtual ~PlayState();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
protected:
	aie::Renderer2D* m_renderer;
	std::shared_ptr<ResourceBase> m_font;
	std::shared_ptr<ResourceBase> m_idleSprite;
	std::shared_ptr<ResourceBase> m_walk1Sprite;
	std::shared_ptr<ResourceBase> m_walk2Sprite;
	std::shared_ptr<ResourceBase> m_currentSprite;
	aie::Input* m_input;
	GameStateManager* m_gsm;
	int m_timer;

	float x;
	float y;
};