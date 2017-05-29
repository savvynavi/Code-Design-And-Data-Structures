#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_playerPosition = {(float)getWindowWidth() / 2, (float)getWindowHeight() / 2};
	m_pFsm = new FiniteStateMachine(2);
	m_player = new GameObject(m_pFsm, m_shipTexture, m_playerPosition);

	m_rand = new Random(m_player);
	m_patrol = new Patrol();

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_pFsm;
	delete m_player;
	delete m_rand;
	delete m_patrol;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//state stuff here
	if(m_rand->test(m_player) == true){
		m_patrol->onUpdate(m_player, deltaTime);
	}
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->drawSprite(m_player->m_texture, m_player->m_position.x, m_player->m_position.y);

	// done drawing sprites
	m_2dRenderer->end();
}