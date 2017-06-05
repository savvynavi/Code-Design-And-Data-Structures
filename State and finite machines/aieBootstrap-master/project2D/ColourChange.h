#pragma once
#include"Condition.h"
#include"Vector2.h"

class GameObject;

class ColourChange : public Condition{
public:
	ColourChange(bool input);
	virtual ~ColourChange();
	virtual bool test(GameObject *object) const;
protected:
	bool m_input;
};