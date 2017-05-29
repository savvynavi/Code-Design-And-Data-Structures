#pragma once
#include"State.h"
#include"GameObject.h"

class Patrol : public State{
public:
	Patrol();
	virtual ~Patrol();
	void onEnter(GameObject *object);
	void onExit(GameObject *object);
	void onUpdate(GameObject *object, float detltaTime);
protected:
	Vector2 m_newPos;
};