#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

//Resource Manager
#include"Resource.h"
#include"ResourceManager.h"
#include"Player.h"

//singleton
#include"ResourceBase.h"

class Application2D : public aie::Application {
public:
	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:


	aie::Renderer2D*				m_2dRenderer;
	//std::shared_ptr<ResourceBase>	m_texture;
	std::shared_ptr<ResourceBase>	m_shipTexture;
	
	//Resource Manager


	float m_cameraX, m_cameraY;
	float m_timer;
};