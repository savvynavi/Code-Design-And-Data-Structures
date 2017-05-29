#pragma once
#include"FiniteStateMachine.h"
#include"Texture.h"
#include"Vector2.h"

class GameObject{
public:
	GameObject(FiniteStateMachine *fsm, aie::Texture *texture, Vector2 pos);
	virtual ~GameObject();
	void update(float deltaTime);

	FiniteStateMachine *m_fsm = nullptr;
	Vector2 m_position;
	aie::Texture *m_texture;
};