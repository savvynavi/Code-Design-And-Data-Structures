#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include<memory>
#include<iostream>

Application2D::Application2D(){

}

Application2D::~Application2D(){

}

bool Application2D::startup(){
	
	m_2dRenderer = new aie::Renderer2D();

	ResourceManager::getInstance().get("./textures/ship.png", ResourceManager::TEXTURE);
	//ResourceManager::getInstance().get("./textures/numbered_grid.tga", ResourceManager::TEXTURE);
	//RESOURCE MANAGER STUFF

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown(){
	delete m_2dRenderer;
	//RESOURCE MANAGEMENT

	system("pause");

}

void Application2D::update(float deltaTime){

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

}

void Application2D::draw(){

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->drawSprite(m_shipTexture->as<aie::Texture>(), 150, 150);
	//m_2dRenderer->drawSprite((aie::Texture*)m_shipTexture->getData(), 150, 150);


	// done drawing sprites
	m_2dRenderer->end();
}