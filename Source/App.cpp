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

	GameManager::GetInstance().Initialize();
}

void App::InternalInput()
{
	m_Window->PollEvents();
}

void App::InternalUpdate()
{
	m_TimeManager->Update();
	float deltaTime = m_TimeManager->GetDeltaTime();

	m_PhysicsManager->Update(deltaTime);

	// TODO: put this in ball update
	if (!m_IsBallFree) {
		for (auto& ball : EntityManager::GetInstance().GetEntitiesByType<Ball>())
		{
			std::vector <std::shared_ptr<Player>> player = EntityManager::GetInstance().GetEntitiesByType<Player>();
			m_IsBallFree = ball->IsBallFree();
			if (!m_IsBallFree)
			{
				ball->SetDirectionY(0);
				ball->SetDirectionX(player.front()->GetDirection());
				ball->SetSpeed(player.front()->GetSpeed());
			}
			
		}
	}

	for (auto& element : EntityManager::GetInstance().GetAllEntities())
	{	
		element->Update(deltaTime);
	}
}

void App::InternalRender()
{
	m_Window->Draw();
}
