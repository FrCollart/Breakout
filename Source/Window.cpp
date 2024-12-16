#include "Window.h"

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
		if (event.type == sf::Event::KeyPressed)
		{
			//TODO : Link input to player movements & interactions
			if (event.key.code == sf::Keyboard::Space) { std::cout << "SpaceBar" << std::endl; }
			if (event.key.code == sf::Keyboard::Left) { std::cout << "Left" << std::endl; }
			if (event.key.code == sf::Keyboard::Right) { std::cout << "Right" << std::endl; }
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

void Window::InternalDisplay()
{
	m_Window.display();
}
