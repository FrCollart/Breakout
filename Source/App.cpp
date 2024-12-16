#include "App.h"
#include "Ball.h"

void App::Run()
{
	InternalInit();	

	// Init TimaManager delta time
	m_TimeManager->Update();

	while (m_Window->IsOpen())
	{
		InternalInput();
		InternalUpdate();
		InternalRender();
	}
}

void App::InternalInit()
{
	// Initialize game components
	m_Window = std::make_unique<Window>();
	m_TimeManager = std::make_unique<TimeManager>();
	m_PhysicsManager = std::make_unique<PhysicsManager>();
}

void App::InternalInput()
{
	m_Window->PollEvents();
}

void App::InternalUpdate()
{
	m_TimeManager->Update();
	float deltaTime = m_TimeManager->GetDeltaTime();
}

void App::InternalRender()
{
	// TEST ONLY
	/*sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(100, 100);*/

	Ball *circle = new Ball(50);

	sf::RectangleShape rectangle(sf::Vector2f(120, 60));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(300, 200);

	std::vector<std::reference_wrapper<sf::Drawable>> drawables = {rectangle};
	// END OF TEST

	m_Window->Draw(drawables);
}
