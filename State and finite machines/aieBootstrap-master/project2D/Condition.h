#pragma once

class Condition{
public:
	virtual ~Condition() {}
	virtual bool test(GameObject*) const = 0;
};

