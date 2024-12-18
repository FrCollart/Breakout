#include "Window.h"

#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"

#include <memory>

//Temp include
#include <iostream>

void Window::PollEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			//TODO : Link input to player movements & interactions
			if (event.key.code == sf::Keyboard::Space)
			{
				std::cout << "SpaceBar" << std::endl;
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				InternalSetPlayerDirection(-1.0f);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				InternalSetPlayerDirection(1.0f);
			}
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			InternalSetPlayerDirection(0.0f);
		}
	}
}

bool Window::IsOpen() const
{
	return m_Window.isOpen();
}

void Window::Clear()
{
	m_Window.clear();
}

void Window::Draw()
{
	Clear();

	for (const auto& entity : EntityManager::GetInstance().GetAllEntities())
	{
		auto sprite = entity->GetSprite();

		if (!sprite.expired())
		{
			m_Window.draw(*sprite.lock());
		}
	}

	InternalDisplay();
}

void Window::InternalDisplay()
{
	m_Window.display();
}

void Window::InternalSetPlayerDirection(float direction)
{
	auto playersList = EntityManager::GetInstance().GetEntitiesByType<Player>();
	if (playersList.empty())
	{
		return;
	}
	playersList.front()->SetDirection(direction);
}
