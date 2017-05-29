#pragma once
#include"State.h"
#include"Condition.h"
#include"GameObject.h"

class Transition final{
public: 
	Transition(Condition *condition, State *target);
	~Transition();
	bool isConditionMet(GameObject *gameObject)const;
	State *getTargetState()const;

private:
	State *m_state; 
	Condition *m_condition;
};