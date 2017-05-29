#pragma once
#include"GameObject.h"
#include"Condition.h"

// would test if a game object is within range of a target game object 
class WithinRangeCondition : public Condition{
public: 
	WithinRangeCondition(GameObject *target, float range);
	virtual~WithinRangeCondition();
	virtual bool test(GameObject *go) const;
protected: 
	GameObject *m_target;
	float m_range;
};