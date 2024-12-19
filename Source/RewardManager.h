#pragma once
#include <SFML/Graphics/Text.hpp>
class RewardManager
{
public:
	static RewardManager& GetInstance();

	RewardManager(const RewardManager&) = delete;
	RewardManager& operator=(const RewardManager&) = delete;

	void AddPlayerPoint(int value);
	int GetPlayerPoint() const;
	void InitializePlayerPointText();

	sf::Text GetPlayerPointText() const;
	void CanAddBonusBall();

private:
	int m_PlayerPoint = 0;
	sf::Text m_PlayerPointText;
	int m_chanceOfGainABall = 10;

	void AddBonusBall();
	RewardManager() = default;
	~RewardManager() = default;
};