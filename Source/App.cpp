#include "App.h"

#include "Ball.h"
#include "EntityManager.h"

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

	auto& entityManager = EntityManager::GetInstance();

	auto circle = std::make_shared<Ball>(50.0f);
	entityManager.AddEntity(circle);
	// END OF TEST

	m_Window->Draw();
}
