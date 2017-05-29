#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include"Vector2.h"
#include"FiniteStateMachine.h"
#include"State.h"
#include"Patrol.h"
#include"Transition.h"
#include"Condition.h"
#include"GameObject.h"
#include"Random.h"

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
	Vector2				m_playerPosition;
	GameObject*			m_player;
	FiniteStateMachine*	m_pFsm;
	Random*				m_rand;
	Patrol*				m_patrol;

	float m_cameraX, m_cameraY;
	float m_timer;
};