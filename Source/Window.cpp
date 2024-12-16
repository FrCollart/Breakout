#include "Window.h"

void Window::PollEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
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

void Window::Display()
{
	m_Window.display();
}
