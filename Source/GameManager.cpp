#include "GameManager.h"

#include "EntityManager.h"
#include "RewardManager.h"
#include "BrickGrid.h"
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "GameConsts.h"

#include <cstdio>
#include <string>

GameManager& GameManager::GetInstance()
{
	static GameManager instance;
	return instance;
}

void GameManager::Initialize(int level)
{
	RewardManager::GetInstance().InitializePlayerPointText();

	// Reconstruct levelPath
	std::string levelPath;

	if (level == -1)
	{
		char buffer[100];
		sprintf_s(buffer, sizeof(buffer), LOSE_PATH);
		levelPath = buffer;
	}
	else if (level == 0)
	{
		char buffer[100];
		sprintf_s(buffer, sizeof(buffer), WIN_PATH);
		levelPath = buffer;
	}
	else
	{
		levelPath = LEVEL_PATH + std::to_string(level) + ".txt";
	}

	BrickGrid brickGrid;
	brickGrid.ImportMap(levelPath);

	if (level <= 0) return;

	std::shared_ptr<Player> player = std::make_shared<Player>((float)(WINDOW_WIDTH / 2), (float)(WINDOW_HEIGHT - WINDOW_HEIGHT / 10));
	EntityManager::GetInstance().AddEntity(player);

	auto ball = std::make_shared<Ball>((float)(WINDOW_WIDTH / 2), ((WINDOW_HEIGHT - WINDOW_HEIGHT / 10) - DEFAULT_BALL_SIZE * 2), DEFAULT_BALL_SIZE);
	EntityManager::GetInstance().AddEntity(ball);
}

void GameManager::CheckGameStatus()
{
	switch (m_GameState)
	{
	case GameState::AIMING:
	{
		// Called when the player launches the ball
		OnPlay();
		break;
	}
	case GameState::PLAYING:
	{
		// Check if all bricks are destroyed
		auto bricks = EntityManager::GetInstance().GetEntitiesRawByType<Brick>();
		if (bricks.empty())
		{
			OnEnd(GameState::WIN);
			break;
		}

		auto balls = EntityManager::GetInstance().GetEntitiesRawByType<Ball>();
		if (balls.empty())
		{
			OnEnd(GameState::LOSE);
		}

		break;
	}
	case GameState::WIN:
	{
		OnReplay();
		break;
	}
	case GameState::LOSE:
	{
		OnReplay();
		break;
	}
	}
}

void GameManager::OnReplay()
{
	m_GameState = GameState::AIMING;
	EntityManager::GetInstance().ClearEntities();
	Initialize();
}

void GameManager::OnPlay()
{
	m_GameState = GameState::PLAYING;
}

void GameManager::OnEnd(GameState state)
{
	m_GameState = state;
	EntityManager::GetInstance().ClearEntities();
	Initialize(state == GameState::WIN ? 0 : -1);
}
