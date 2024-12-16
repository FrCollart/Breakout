#include "App.h"

#include "Window.h"

void App::Run()
{
	std::unique_ptr<Window> window = std::make_unique<Window>();
	
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(100, 100);

	sf::RectangleShape rectangle(sf::Vector2f(120, 60));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(300, 200);

	std::vector<std::reference_wrapper<sf::Drawable>> drawables = { circle, rectangle };

	while (window->IsOpen())
	{
		window->PollEvents();
		window->Clear();
		window->Draw(drawables);
		window->Display();
	}
}
