#pragma once
#include"GameState.h"
#include"Application2d.h"

class GameStateManager;

//somehw include app2d in this and hold an instance of it to call quit() on
class Quit : public GameState{
public:
	Quit(GameStateManager* gsm, Application2D* app);
	~Quit();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
private:
	Application2D* app;
	GameStateManager* m_gsm;
};