#pragma once
#include"Component.h"
#include<vector>

class GameObject{
	GameObject(){}
	virtual ~GameObject(){}

	void addComponent(const ComponentPtr& component){
		m_components.push_back(component);
	}

	virtual void update(float deltaTime){
		for(auto& component : m_components){
			component->update(this, deltaTime);
		}
	}

	virtual void draw(){
		for(auto& component : m_components){
			component->draw(this);
		}
	}

protected:
	std::vector<ComponentPtr> m_components;
};