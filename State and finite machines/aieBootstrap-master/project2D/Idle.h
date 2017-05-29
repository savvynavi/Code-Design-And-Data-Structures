#pragma once
#include"State.h"
#include"GameObject.h"

class Idle : public State{
public:
	Idle();
	virtual ~Idle();
	void onEnter(GameObject *object);
	void onExit(GameObject *object);
	void onUpdate(GameObject *object);
};