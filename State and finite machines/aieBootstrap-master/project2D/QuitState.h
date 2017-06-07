#pragma once
#include"GameState.h"

class GameStateManager;

class QuitState : public GameState{
public:
	QuitState(GameStateManager* gsm);
	virtual ~QuitState();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
protected:
	GameStateManager* m_gsm;
};