#include "App.h"

#include "Window.h"
#include "TimeManager.h"

void App::Run()
{
	std::unique_ptr<Window> window = std::make_unique<Window>();
	std::unique_ptr<TimeManager> timeManager = std::make_unique<TimeManager>();
	
	// TEST ONLY
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(100, 100);

	sf::RectangleShape rectangle(sf::Vector2f(120, 60));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(300, 200);

	std::vector<std::reference_wrapper<sf::Drawable>> drawables = { circle, rectangle };
	// END OF TEST

	while (window->IsOpen())
	{
		window->PollEvents();

		timeManager->Update();
		float deltaTime = timeManager->GetDeltaTime();
		// TODO: Update game logic here

		window->Draw(drawables);
	}
}
