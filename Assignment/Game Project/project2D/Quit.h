#pragma once
#include"GameState.h"
class GameStateManager;

//somehw include app2d in this and hold an instance of it to call quit() on
class Quit : public GameState{
public:
	Quit(GameStateManager* gsm);
	~Quit();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
private:
	GameStateManager* m_gsm;
};