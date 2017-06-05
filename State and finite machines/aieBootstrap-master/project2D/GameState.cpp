#include"GameState.h"

GameState::GameState(){


}
GameState::~GameState(){

}

bool GameState::isActive()const{
	return m_active;
}

void GameState::enter(){
	m_active = true;
	onEnter();
}

void GameState::exit(){
	m_active = false;
	onExit();
}

void GameState::onEnter(){

}

void GameState::onExit(){

}

void GameState::onPushed(){

}

void GameState::onPopped(){

}