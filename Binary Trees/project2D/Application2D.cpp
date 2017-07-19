#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include"Imgui.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

aie::Font* g_systemFont = nullptr;

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	g_systemFont = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	static int value = 0;
	ImGui::InputInt("Value", &value);

	if(ImGui::Button("Insert", ImVec2(150, 0))){
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}

	if(ImGui::Button("Remove", ImVec2(150, 0))){
		m_binaryTree.remove(value);
	}

	if(ImGui::Button("Find", ImVec2(150, 0))){
		m_selectedNode = m_binaryTree.find(value);
	}

	if(ImGui::Button("PreOrder Depthfirst", ImVec2(150, 0))){
		m_binaryTree.DepthFirstPreOrder(m_binaryTree.findRoot());
	}

	if(ImGui::Button("PostOrder Depthfirst", ImVec2(150, 0))){
		m_binaryTree.DepthFirstPostOrder(m_binaryTree.findRoot());
	}

	if(ImGui::Button("InOrder Depthfirst", ImVec2(150, 0))){
		m_binaryTree.DepthFirstInOrder(m_binaryTree.findRoot());
	}

	if(ImGui::Button("Bredthfirst", ImVec2(150, 0))){
		m_binaryTree.BredthFirst(m_binaryTree.findRoot());
	}

	//exit the app
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

	//tree drawing here
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);

	//output some text
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}