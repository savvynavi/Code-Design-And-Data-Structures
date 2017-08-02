#include"Quit.h"
#include"GameStateManager.h"

Quit::Quit(GameStateManager* gsm, Application2D* app){
	m_gsm = gsm;
	this->app = app;
}

Quit::~Quit(){

}

void Quit::onUpdate(float deltaTime){
	app->quit();
}

void Quit::onDraw(){

}