#pragma once
#include"Condition.h"
#include"Vector2.h"

class GameObject;

class Random : public Condition{
public:
	Random(GameObject *object);
	virtual ~Random();
	virtual bool test(GameObject *object) const;
protected:
	GameObject *m_target;
};