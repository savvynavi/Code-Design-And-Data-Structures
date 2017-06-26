#pragma once

#include<memory>

class GameObject;

class Component{
public:
	virtual ~Component(){}
	virtual void update(GameObject* gameObject, float deltaTime) = 0;
	virtual void draw(GameObject* gameObject){}
};

typedef std::shared_ptr<Component> ComponentPtr;