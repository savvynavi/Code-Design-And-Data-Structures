#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include<memory>
#include<iostream>


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_shipTexture = new aie::Texture("./textures/ship.png");
	////FSM STUFF

	////making/placing player object at centre
	//m_playerPosition = {(float)getWindowWidth() / 2, (float)getWindowHeight() / 2};
	//
	//
	////making fsm, gameobject, and states/transition
	//m_pFsm = new FiniteStateMachine(2);
	//m_player = new GameObject(m_pFsm, m_shipTexture, m_playerPosition);
	//
	//Idle* idle = new Idle(m_player);
	//Patrol* patrol = new Patrol();
	//Random* random = new Random(m_player);
	//
	//Transition* transitionIdle = new Transition(random, idle);
	//Transition* transitionPatrol = new Transition(random, patrol);
	//
	//
	////adding transitions
	//patrol->addTransition(transitionIdle);
	//idle->addTransition(transitionPatrol);
	//
	////adding states to fsm, making it start on patrol
	//m_pFsm->addState(0, idle);
	//m_pFsm->addState(1, patrol);
	//m_pFsm->forceState(0);

	////GSM STUFF
	
	////setting up fonts/textures
	//m_font = new aie::Font("./font/consolas_italic.ttf", 20);
	//m_menuTexture = new aie::Texture("./textures/title.png");
	//
	//
	//
	////making gsm, states
	//m_gsm = new GameStateManager(3);
	//SplashScreen* splashScreen = new SplashScreen(m_2dRenderer, m_font, m_gsm);
	//MainMenu* mainMenu = new MainMenu(m_2dRenderer, m_font, m_menuTexture, m_gsm);
	//PlayState* playState = new PlayState(m_2dRenderer, m_font, m_shipTexture, m_gsm);
	//
	////filling gsm with states
	//m_gsm->registerState(SPLASH_SCREEN, splashScreen);
	//m_gsm->registerState(MAIN_MENU, mainMenu);
	//m_gsm->registerState(PLAY_STATE, playState);
	//
	//
	//
	//
	//m_gsm->pushState(SPLASH_SCREEN);//pushed state = current state(as at top), will start with splashscreen


	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_shipTexture;
	delete m_2dRenderer;
	//delete m_player; //Finite state stuff


}

void Application2D::update(float deltaTime){

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//finite state stuff here
	//m_pFsm->update(m_player, deltaTime);

	//Game state stuff here
	//m_gsm->update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	////FINTE STATE STUFF
	//m_2dRenderer->drawSprite(m_player->m_texture, m_player->m_position.x, m_player->m_position.y);

	//GAME STATE STUFF
	//m_gsm->draw();

	// done drawing sprites
	m_2dRenderer->end();
}