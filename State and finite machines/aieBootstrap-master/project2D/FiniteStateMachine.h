#pragma once
#include"State.h"
#include"GameObject.h"
#include<vector>

class FiniteStateMachine {
public: FiniteStateMachine(int stateCount) {
	m_states.resize(stateCount);
}
		virtual~FiniteStateMachine() {
			for(auto state : m_states) delete state;
		}
		void addState(int id, State * newState) {
			m_states[id] = newState;
		}
		void forceState(int id) {
			m_currentState = m_states[id];
		}
		void update(GameObject * gameObject, float deltaTime) {
			if(m_currentState != nullptr) {
				m_currentState > onUpdate(gameObject, deltaTime);
				State * next = m_currentState -> getNextState(gameObject);
				if(next != m_currentState && next != nullptr) {
					m_currentState -> onExit(gameObject);
					m_currentState = next;
					m_currentState -> onEnter(gameObject);
				}
			}
		}

protected: 
	State * m_currentState = nullptr;
		   std::vector < State * > m_states;
};