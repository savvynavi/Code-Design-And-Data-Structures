#include"GameObject.h"


GameObject::GameObject(FiniteStateMachine *fsm, aie::Texture *texture, Vector2 pos){
	m_fsm = fsm;
	m_position = pos;
	m_texture = texture;
}
GameObject::~GameObject(){

}

void GameObject::update(float deltaTime){
	if(m_fsm != nullptr){
		m_fsm->update(this, deltaTime);
	}
}