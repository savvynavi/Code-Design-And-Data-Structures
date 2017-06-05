#pragma once
#include"State.h"
#include"GameObject.h"

class Idle : public State{
public:
	Idle(GameObject* object);
	virtual ~Idle();
	void onEnter(GameObject *object);
	void onExit(GameObject *object);
	void onUpdate(GameObject *object, float dt);
protected:
	Vector2 m_currentPos;
};