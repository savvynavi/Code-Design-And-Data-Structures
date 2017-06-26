#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include<stdlib.h>
#include<random>
#include<time.h>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	srand(time(NULL));

	m_snackFactory = std::unique_ptr<SnackFactory>(new SnackFactory());

	//create some snacks to store in the factory
	std::shared_ptr<Snack> cake(new Snack("cake", "./textures/cake.png"));
	cake->setPosition(200, 100);

	std::shared_ptr<Snack> croissant(new Snack("croissant", "./textures/croissant.png"));
	croissant->setPosition(500, 400);

	m_snackFactory->addPrototype(cake);
	m_snackFactory->addPrototype(croissant);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	static float timer = 0;

	if(timer <= 0){
		timer = 0.5f;

		std::shared_ptr<IPrototype> snackClone;
		if(rand() % 2 == 0){
			snackClone = m_snackFactory->create("cake");
		}else{
			snackClone = m_snackFactory->create("croissant");
		}

		//dynamically cast the shared ptr from Iprototype to Snack
		std::shared_ptr<Snack> snack = std::dynamic_pointer_cast<Snack>(snackClone);
		snack->setVelocity(50 - rand() % 100, 10 - rand() % 100);
		m_snacks.push_back(snack);
	}
	timer -= deltaTime;

	for(auto it = m_snacks.begin(); it != m_snacks.end(); ){
		(*it)->update(deltaTime);
		glm::vec2 pos = (*it)->getPosition();
		if(pos.x < 0 || pos.y < 0 || pos.x > this->getWindowWidth() || pos.y > this->getWindowHeight()){
			it = m_snacks.erase(it);
		}else{
			++it;
		}
	}

	if(input->isKeyDown(aie::INPUT_KEY_ESCAPE)){
		quit();
	}

}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//drawing snacks

	for(std::shared_ptr<Snack> snack : m_snacks){
		snack->draw(m_2dRenderer);
	}
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	

	// done drawing sprites
	m_2dRenderer->end();
}