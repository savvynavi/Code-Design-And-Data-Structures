#pragma once
#include<vector>

class GameState;

class GameStateManager{
public:
	GameStateManager(unsigned int stateCount);
	~GameStateManager();

	void registerState(int id, GameState* state);
	void pushState(int id);
	void popState();

	void update(float deltaTime);

	void draw();

	int activeStateCount()const;
	GameState* getTopState()const;
	GameState* getState(int id)const;
private:
	std::vector<GameState*> m_pushedStates;
	bool m_popState = false;

	std::vector<GameState*> m_stateStack;
	std::vector<GameState*> m_registeredStates;
};