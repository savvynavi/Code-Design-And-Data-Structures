#include"Transition.h"

Transition::Transition(Condition *condition, State *target){
	m_condition = condition;
	m_state = target;
}

Transition::~Transition(){
	delete m_condition;
}

bool Transition::isConditionMet(GameObject *gameObject) const{
	return m_condition->test(gameObject);
}

State* Transition::getTargetState() const{
	return m_state;
}