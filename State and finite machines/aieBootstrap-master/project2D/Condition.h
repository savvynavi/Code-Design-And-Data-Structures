#pragma once
#include"GameObject.h"

class Condition{
public:
	virtual ~Condition();
	virtual bool test(GameObject*) const = 0;
};