#pragma once
#include"FiniteStateMachine.h"
#include"Texture.h"

class GameObject{
public:
	GameObject(FiniteStateMachine *fsm, aie::Texture *texture) {m_fsm = fsm;}
	virtual ~GameObject(){}

	void update(float deltaTime){
		if(m_fsm != nullptr){
			m_fsm->update(this, deltaTime);
		}
	}

protected:
	FiniteStateMachine *m_fsm = nullptr;
};