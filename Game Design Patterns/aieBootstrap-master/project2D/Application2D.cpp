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

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	//RESOURCE MANAGER STUFF


	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown(){
	delete m_texture;
	delete m_shipTexture;
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


	// done drawing sprites
	m_2dRenderer->end();
}