#include"State.h"
#include"Transition.h"
#include"GameObject.h"

State::~State(){
	for(auto t : m_transitions){
		delete t;
	}
}

void State::onEnter(GameObject *object){

}

void State::onExit(GameObject *object){

}

void State::onUpdate(GameObject *object, float dt){

}

void State::addTransition(Transition * transition){
	m_transitions.push_back(transition);
}

State* State::getNextState(GameObject *gameObject){
	for(auto transition : m_transitions){
		if(transition->isConditionMet(gameObject)){
			return (transition->getTargetState());
		}
	} // no state change, return nullptr; 
}