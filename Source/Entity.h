#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(float posX , float posY, sf::Texture m_img);
	Entity(float posX, float posY);
	Entity();
	~Entity();

	void LoadTexture(std::string filePath);
	float GetX() const;
	float GetY() const;


protected:
	float m_PosX;
	float m_PosY;
	sf::Texture m_Text;
};

