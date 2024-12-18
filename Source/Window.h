#pragma once

#include <SFML/Graphics.hpp>
#include <concepts>

#include "GameConsts.h"

class Window
{
public:
    Window()
        : m_Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
    {}
    Window(const std::string& title, unsigned int width, unsigned int height)
        : m_Window(sf::VideoMode(width, height), title)
    {}
    ~Window() {}

    void PollEvents();
    bool IsOpen() const;
    void Clear();
    void Draw();

private:
    void InternalDisplay();
	void InternalSetPlayerDirection(float direction);

private:
    sf::RenderWindow m_Window;
};