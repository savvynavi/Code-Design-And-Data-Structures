#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include"Font.h"
#include"Vector2.h"

#include"FiniteStateMachine.h"
#include"GameObject.h"

#include"Transition.h"

#include"Condition.h"
#include"Random.h"
#include"ColourChange.h"

#include"State.h"
#include"Patrol.h"
#include"Idle.h"

//Game State Manager
#include"GameState.h"
#include"GameStateManager.h"
#include"SplashScreen.h"

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
	aie::Texture*		m_shipTexture;
	//Finite state vars
	Vector2				m_playerPosition;
	GameObject*			m_player;
	FiniteStateMachine*	m_pFsm;
	float m_r;
	float m_g;
	float m_b;
	
	//Game state vars
	GameStateManager*	m_gsm;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
};