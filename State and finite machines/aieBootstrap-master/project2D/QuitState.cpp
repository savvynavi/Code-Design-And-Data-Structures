#include"QuitState.h"
#include"GameStateManager.h"
#include"Application.h"

QuitState::QuitState(GameStateManager* gsm){
	m_gsm = gsm;
}

QuitState::~QuitState(){

}

void QuitState::onUpdate(float deltaTime){
	while(m_gsm->activeStateCount() != 0){
		m_gsm->popState();
	}
	//Application->quit();
}

void QuitState::onDraw(){

}