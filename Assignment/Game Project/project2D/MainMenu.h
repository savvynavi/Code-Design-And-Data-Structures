#pragma once
#include"GameState.h"
#include"Renderer2D.h"
#include"Font.h"
#include"Audio.h"
#include"Input.h"
#include"Texture.h"
#include"Resource.h"
#include"ResourceManager.h"
#include"ResourceBase.h"


class Application2D;
class GameStateManager;

class MainMenu: public GameState{
public:
	//maybe instantiate menu texture inside this gs, as not use elsewhere(unlike audio, which should be outside as used elsewhere)
	MainMenu(aie::Renderer2D* renderer, std::shared_ptr<ResourceBase> font, std::shared_ptr<ResourceBase> rTexture, std::shared_ptr<ResourceBase> audio, GameStateManager* gsm);
	virtual ~MainMenu();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
protected:
	aie::Renderer2D* m_renderer;
	std::shared_ptr<ResourceBase> m_font;
	std::shared_ptr<ResourceBase> m_audio;
	aie::Input* m_input;
	std::shared_ptr<ResourceBase> m_texture;
	std::shared_ptr<ResourceBase> m_buttonSound;
	int m_menuSelect;
	float m_selectorHeight;
	GameStateManager* m_gsm;
};