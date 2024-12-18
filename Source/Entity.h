#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Entity
{
public:
	Entity(float posX, float posY);
	Entity();
	~Entity();

	float GetX() const;
	float GetY() const;
	std::weak_ptr<sf::Drawable> GetSprite();

	void SetX(float x);
	void SetY(float y);

	void LoadTexture(const char* filePath);

	virtual void Update(float deltaTime) =0;
	virtual void OnCollide() = 0;

	// Since Sprite is different for every entity, the offset between the real position and the sprite position is different as well
	virtual void SetSpritePos(float newX, float newY) = 0;
	
protected:
	float m_PosX = 0.0f;
	float m_PosY = 0.0f;
	std::shared_ptr<sf::Drawable> m_Sprite = nullptr;
};

