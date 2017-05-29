#pragma once
#include"GameObject.h"
#include"Vector2.h"

class Player : public GameObject{
public:
	void update(float deltaTime);
protected:
	Player *m_player;
	float m_position;
};