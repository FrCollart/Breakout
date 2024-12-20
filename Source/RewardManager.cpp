#include "RewardManager.h"
#include "Ball.h"
#include "EntityManager.h"
#include "GameConsts.h"
#include <random>
#include <iostream>

RewardManager& RewardManager::GetInstance()
{
	static RewardManager instance;
	return instance;
}

int RewardManager::GetPlayerPoint() const
{
	return m_PlayerPoint;
}

void RewardManager::InitializePlayerPointText()
{
	m_PlayerPointText = sf::Text();

	sf::Font font;
	if (!font.loadFromFile("font.ttf")) {
		return;
	}

	m_PlayerPointText.setFont(font);
	m_PlayerPointText.setString(std::to_string(m_PlayerPoint));
	m_PlayerPointText.setCharacterSize(30);
	m_PlayerPointText.setFillColor(sf::Color::White);
	m_PlayerPointText.setStyle(sf::Text::Bold);
	m_PlayerPointText.setPosition(30, 30);
}

sf::Text RewardManager::GetPlayerPointText() const
{
	return m_PlayerPointText;
}

void RewardManager::CanAddBonusBall()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distribBallChance(1, m_chanceOfGainABall);

	int random_number = distribBallChance(gen);

	if (random_number == 1) {
		AddBonusBall();
	}
}

void RewardManager::AddBonusBall()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distribDirX(-1.0, 1.0);
	std::uniform_real_distribution<> distribSpeed(50, 150);
	std::uniform_real_distribution<> distribWidth(0, WINDOW_WIDTH);

	double random_DirectionX = distribDirX(gen);
	double random_Speed = distribSpeed(gen);
	double random_Width = distribWidth(gen);

	auto ball = std::make_shared<Ball>((float)random_Width, ((WINDOW_HEIGHT - WINDOW_HEIGHT / 10) - DEFAULT_BALL_SIZE * 2), DEFAULT_BALL_SIZE);
	ball->SetDirectionX((float)random_DirectionX);
	ball->SetSpeed((float)random_Speed);
	ball->FreeTheBall();
	EntityManager::GetInstance().AddEntity(ball);
}

void RewardManager::AddPlayerPoint(int value)
{
	m_PlayerPoint += value;
	m_PlayerPointText.setString(std::to_string(m_PlayerPoint));
}
