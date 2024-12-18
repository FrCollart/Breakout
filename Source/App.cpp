#include "App.h"

#include "Ball.h"
#include "Player.h"
#include "EntityManager.h"
#include "BrickGrid.h"
#include "GameConsts.h"

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

	// TEST ONLY
	BrickGrid brickGrid;
	brickGrid.ImportMap("Ressource/map.txt");

	EntityManager& temp = EntityManager::GetInstance();
	std::shared_ptr<Player> tempPlayer = std::make_shared<Player>();

	tempPlayer->SetX(WINDOW_WIDTH / 2);
	tempPlayer->SetY(700.0f);

	temp.AddEntity(tempPlayer);
	temp.SetPlayer(tempPlayer);

	/*auto& entityManager = EntityManager::GetInstance();

	auto circle = std::make_shared<Ball>(400.0f,600.0f,10.0f);
	entityManager.AddEntity(circle);*/
	// END OF TEST
	
}

void App::InternalInput()
{
	m_Window->PollEvents();
}

void App::InternalUpdate()
{
	m_TimeManager->Update();
	float deltaTime = m_TimeManager->GetDeltaTime();
	auto& entityVector = EntityManager::GetInstance().GetEntities();

	for (const auto& element : entityVector) {
		element->Update(deltaTime);
	}
}

void App::InternalRender()
{
	// TEST ONLY
	/*sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(100, 100);*/

	// END OF TEST

	m_Window->Draw();
}
