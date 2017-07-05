#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

//Resource Manager
#include"Resource.h"
#include"ResourceManager.h"

//singleton
#include"ResourceBase.h"

//snack factory
#include"SnackFactory.h"
#include"Snack.h"
#include<list>

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
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	std::unique_ptr<SnackFactory> m_snackFactory;
	std::list<std::shared_ptr<Snack>> m_snacks;

	float m_cameraX, m_cameraY;
	float m_timer;
};