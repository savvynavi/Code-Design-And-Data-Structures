#include"Idle.h"

Idle::Idle(GameObject* object){
	m_currentPos = object->m_position;
}

Idle::~Idle(){

}

void Idle::onEnter(GameObject *object){
	m_currentPos = object->m_position;
}

void Idle::onExit(GameObject *object){

}

void Idle::onUpdate(GameObject *object, float dt){
	object->m_position = m_currentPos;
}