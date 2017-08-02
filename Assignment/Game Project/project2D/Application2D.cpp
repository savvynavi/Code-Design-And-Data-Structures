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
	m_font = ResourceManager::getInstance().get("./font/consolas_italic.ttf", ResourceManager::FONT);
	m_menuTexture = ResourceManager::getInstance().get("./textures/title.png", ResourceManager::TEXTURE);
	m_menuMusic = ResourceManager::getInstance().get("./audio/happy.wav", ResourceManager::AUDIO);

	//setting up gsm's
	m_gsm = new GameStateManager(5);
	SplashScreen* splashScreen = new SplashScreen(m_2dRenderer, m_font, m_gsm);
	MainMenu* mainMenu = new MainMenu(m_2dRenderer, m_font, m_menuTexture, m_menuMusic, m_gsm);
	PlayState* playState = new PlayState(m_2dRenderer, m_font, m_gsm);
	PauseMenu* pauseMenu = new PauseMenu(m_2dRenderer, m_font, m_gsm);
	Quit* quit = new Quit(m_gsm, this);
	
	//filling gsm with states
	m_gsm->registerState(SPLASH_SCREEN, splashScreen);
	m_gsm->registerState(MAIN_MENU, mainMenu);
	m_gsm->registerState(PLAY_STATE, playState);
	m_gsm->registerState(PAUSE_MENU, pauseMenu);
	m_gsm->registerState(QUIT, quit);

	m_gsm->pushState(SPLASH_SCREEN);//pushed state = current state(as at top), will start with splashscreen

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_gsm->update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_gsm->draw();

	// done drawing sprites
	m_2dRenderer->end();
}