#pragma once

enum GameState
{
	AIMING,
	PLAYING,
	WIN,
	LOSE
};

class GameManager
{
public:
	static GameManager& GetInstance();

	void Initialize(int level = 1);
	void CheckGameStatus();

	GameState GetGameState() const { return m_GameState; }

private:
	GameManager() = default;
	~GameManager() = default;

	void OnReplay();
	void OnPlay();

	void OnEnd(GameState state);

	GameState m_GameState = GameState::AIMING;
};

