#pragma once

#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"
#include"Audio.h"
#include"Input.h"
#include"Resource.h"
#include"ResourceManager.h"
#include"ResourceBase.h"

class GameStateManager;

class PauseMenu : public GameState{
public:
	PauseMenu(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, GameStateManager* gsm);
	~PauseMenu();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	virtual void onEnter();
private:
	aie::Renderer2D* m_renderer;
	float m_selectorHeight;
	aie::Input* m_input;
	std::shared_ptr<ResourceBase> m_font;
	std::shared_ptr<ResourceBase> m_buttonSound;
	GameStateManager* m_gsm;
	int m_menuSelect;
};