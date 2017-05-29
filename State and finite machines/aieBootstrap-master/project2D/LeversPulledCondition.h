#pragma once
#include"Condition.h"
#include"GameObject.h"
#include<vector>

// could be used to trigger a transition once a player has pulled all levers 
class LeversPulledCondition : public Condition {
public: 
	LeversPulledCondition(const std::vector < bool > &triggers) : m_triggers(triggers) {}
	virtual~LeversPulledCondition() {}
	
	virtual bool test(GameObject *go) const {
		for(bool b : m_triggers){
			if(b == false) return false;
		}
		return true;
	}
};