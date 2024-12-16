#pragma once

#include <SFML/Graphics.hpp>
#include <concepts>

#include "GameConsts.h"

template <typename T>
concept DrawableIterator = requires(T t)
{
    { std::begin(t) } -> std::input_iterator;
    { *std::begin(t) } -> std::convertible_to<const sf::Drawable&>;
};

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
    template<DrawableIterator Iterator>
    void Draw(const Iterator& drawables);

private:
    void InternalDisplay();

private:
    sf::RenderWindow m_Window;
};

template<DrawableIterator Iterator>
inline void Window::Draw(const Iterator& drawables)
{
    Clear();
	for (const auto& drawable : drawables)
	{
		m_Window.draw(drawable);
	}
    InternalDisplay();
}