#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(float posX , float posY, sf::Texture m_img);
	Entity(float posX, float posY);
	Entity();
	~Entity();

	void LoadTexture(sf::Texture img);
	const float GetX();
	const float GetY();


private:
	float m_posX;
	float m_posY;
	sf::Texture m_img;
};

