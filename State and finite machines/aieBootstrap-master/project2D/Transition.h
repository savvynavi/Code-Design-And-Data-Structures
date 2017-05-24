#pragma once
#include"State.h"
#include"Condition.h"
#include"GameObject.h"

class Transition final{
public: Transition(Condition * condition, State * target) {
	m_condition = condition;
	m_state = target;
}~Transition() {
	delete m_condition;
}
bool isConditionMet(GameObject * gameObject) const {
	return m_condition -> test(gameObject);
}
State * getTargetState() const {
	return m_state;
}
private: State * m_state; Condition * m_condition;
};