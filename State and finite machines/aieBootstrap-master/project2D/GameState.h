#pragma once

class GameState{
	friend class GameStateManager;
public:
	GameState();
	virtual ~GameState();
	bool isActive()const;
protected:
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw() = 0;

	void enter();
	void exit();

	virtual void onEnter();
	virtual void onExit();
	virtual void onPushed();
	virtual void onPopped();

private:
	bool m_active = false;
};